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
 * Examine MagiSync time domains
 */

#include <canlib.h>
#include <stdio.h>

#define NUMBER_OF_CHANNELS 5

static void check(char *id, canStatus stat)
{
    if (stat != canOK) {
        char buf[50];
        buf[0] = '\0';
        canGetErrorText(stat, buf, sizeof(buf));
        printf("%s: failed, stat=%d (%s)\n", id, (int)stat, buf);
    }
}

static void printUsageAndExit(char *prgName)
{
    printf("Usage: '%s <channel> <channel> [<channel> ...]'\n", prgName);
    exit(1);
}

int main(int argc, char *argv[])
{
    int h[NUMBER_OF_CHANNELS];
    canStatus stat;
    int i, n;
    kvTimeDomain tDomain;
    kvTimeDomainData tData;
    n = argc - 1;

    if (n < 2) {
        printf("Error: At least two channels required.\n");
        printUsageAndExit(argv[0]);
    }

    if (n > NUMBER_OF_CHANNELS) {
        printf("Error: Too many channels. Got %d, expected no more than %d. "
               "Increase NUMBER_OF_CHANNELS and rebuild this example.\n",
               n, NUMBER_OF_CHANNELS);
        printUsageAndExit(argv[0]);
    }

    canInitializeLibrary();

    // Create a time domain for my handles.
    stat = kvTimeDomainCreate(&tDomain);
    if (stat != canOK) {
        check("kvTimeDomainCreate", stat);
        return 1;
    }

    for (i = 0; i < n; i++) {
        int ch;
        ch = atoi(argv[i + 1]);
        h[i] = canOpenChannel(ch, 0);
        if (h[i] < 0) {
            printf("canOpenChannel %d failed\n", ch);
            check("", h[i]);
            return 1;
        }
    }

    // Add the handles to the domain.
    for (i = 0; i < n; i++) {
        stat = kvTimeDomainAddHandle(tDomain, h[i]);
        if (stat != canOK) {
            printf("Failed to add handle %d to tDomain, ", i);
            check("kvTimeDomainAddHandle", stat);
            return 1;
        }
    }

    // Request some data from the domain and try to interpret it.
    stat = kvTimeDomainGetData(tDomain, &tData, sizeof(tData));
    if (stat != canOK) {
        check("kvTimeDomainGetData", stat);
        return 1;
    }

    if (tData.nMagiSyncGroups > 1) {
        printf("Consider connecting the Kvaser MagiSync enabled ");
        printf("interfaces through the same USB root hub!\n\n");
    }

    if (tData.nMagiSyncGroups == 1) {
        printf("All Kvaser MagiSync enabled interfaces are ");
        printf("connected through the same USB root hub and ");
        printf("will therefore be synchronized.\n\n");
    }

    if (tData.nMagiSyncedMembers == n) {
        printf("All handles have the Kvaser MagiSync feature enabled!\n\n");
    }

    // Reset the time on all handles in tDomain.
    stat = kvTimeDomainResetTime(tDomain);
    if (stat != canOK) {
        check("kvTimeDomainResetTime", stat);
        return 1;
    }

    // Final cleanup
    stat = kvTimeDomainDelete(tDomain);
    if (stat != canOK) {
        check("kvTimeDomainDelete", stat);
        return 1;
    } else {
        printf("All resources used by tDomain and its members ");
        printf("returned to system\n");
    }

    stat = canUnloadLibrary();
    if (stat != canOK) {
        check("canUnloadLibrary", stat);
        return 1;
    }

    return 0;
}
