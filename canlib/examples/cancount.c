/*
**             Copyright 2023 by Kvaser AB, Molndal, Sweden
**                         http://www.kvaser.com
**
** This software is dual licensed under the following two licenses:
** BSD-new and GPLv2. You may use either one. See the included
** COPYING file for details.
**
** License: BSD-new
** ==============================================================================
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the <organization> nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
** IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
**
**
** License: GPLv2
** ==============================================================================
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
**
**
** IMPORTANT NOTICE:
** ==============================================================================
** This source code is made available for free, as an open license, by Kvaser AB,
** for use with its applications. Kvaser AB does not accept any liability
** whatsoever for any third party patent or other immaterial property rights
** violations that may result from any usage of this source code, regardless of
** the combination of source code and various applications that it can be used
** in, or with.
**
** -----------------------------------------------------------------------------
*/

/*
 * Kvaser Linux Canlib
 * Count the number of messages/second on a CAN channel
 */

#include <canlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define ALARM_INTERVAL_IN_S (1)
#define READ_WAIT_INFINITE  (unsigned long)(-1)

static unsigned int msgCounter = 0;
static unsigned int std = 0, ext = 0, rtr = 0, err = 0, over = 0;

static void check(char *id, canStatus stat)
{
    if (stat != canOK) {
        char buf[50];
        buf[0] = '\0';
        canGetErrorText(stat, buf, sizeof(buf));
        printf("%s: failed, stat=%d (%s)\n", id, (int)stat, buf);
    }
}

static void sighand(int sig, siginfo_t *info, void *ucontext)
{
    static unsigned int last;
    (void)info;
    (void)ucontext;

    switch (sig) {
    case SIGINT:
        break;
    case SIGALRM:
        if (msgCounter - last) {
            printf("msg/s = %d, total=%u, std=%u, ext=%u, err=%u, over=%u\n",
                   (msgCounter - last) / ALARM_INTERVAL_IN_S, msgCounter, std, ext, err, over);
        }
        last = msgCounter;
        alarm(ALARM_INTERVAL_IN_S);
        break;
    }
}

static void printUsageAndExit(char *prgName)
{
    printf("Usage: '%s <channel>'\n", prgName);
    exit(1);
}

int main(int argc, char *argv[])
{
    canHandle hnd;
    canStatus stat;
    int channel;
    struct sigaction sigact;

    if (argc != 2) {
        printUsageAndExit(argv[0]);
    }

    {
        char *endPtr = NULL;
        errno = 0;
        channel = strtol(argv[1], &endPtr, 10);
        if ((errno != 0) || ((channel == 0) && (endPtr == argv[1]))) {
            printUsageAndExit(argv[0]);
        }
    }

    /* Use sighand as our signal handler for SIGALRM */
    sigact.sa_flags = SA_SIGINFO | SA_RESTART;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_sigaction = sighand;
    if (sigaction(SIGALRM, &sigact, NULL) != 0) {
        perror("sigaction SIGALRM failed");
        return -1;
    }
    /* Use sighand and allow SIGINT to interrupt syscalls */
    sigact.sa_flags = SA_SIGINFO;
    if (sigaction(SIGINT, &sigact, NULL) != 0) {
        perror("sigaction SIGINT failed");
        return -1;
    }

    printf("Counting CAN messages on channel %d\n", channel);

    canInitializeLibrary();

    /* Open channel, set parameters and go on bus */
    hnd = canOpenChannel(channel,
                         canOPEN_EXCLUSIVE | canOPEN_REQUIRE_EXTENDED | canOPEN_ACCEPT_VIRTUAL);
    if (hnd < 0) {
        printf("canOpenChannel %d", channel);
        check("", hnd);
        return -1;
    }
    stat = canSetBusParams(hnd, canBITRATE_1M, 0, 0, 0, 0, 0);
    check("canSetBusParams", stat);
    if (stat != canOK) {
        goto ErrorExit;
    }
    stat = canBusOn(hnd);
    check("canBusOn", stat);
    if (stat != canOK) {
        goto ErrorExit;
    }

    alarm(ALARM_INTERVAL_IN_S);

    do {
        long id;
        unsigned char msg[8];
        unsigned int dlc;
        unsigned int flag;
        unsigned long time;

        stat = canReadWait(hnd, &id, &msg, &dlc, &flag, &time, READ_WAIT_INFINITE);

        if (stat == canOK) {
            if (flag & canMSG_ERROR_FRAME) {
                err++;
            } else {
                if (flag & canMSG_STD)
                    std++;
                if (flag & canMSG_EXT)
                    ext++;
                if (flag & canMSG_RTR)
                    rtr++;
                if (flag & canMSGERR_OVERRUN)
                    over++;
            }
            msgCounter++;
        } else {
            if (errno == 0) {
                check("\ncanReadWait", stat);
            } else {
                perror("\ncanReadWait error");
            }
        }

    } while (stat == canOK);

    sighand(SIGALRM, NULL, NULL);

ErrorExit:

    alarm(0);
    stat = canBusOff(hnd);
    check("canBusOff", stat);
    stat = canClose(hnd);
    check("canClose", stat);
    stat = canUnloadLibrary();
    check("canUnloadLibrary", stat);

    return 0;
}
