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
**
** WARNING: THIS FILE IS AUTOMATICALLY GENERATED - EDIT AT YOUR OWN PERIL!
*/

#ifndef __KV_DEV_DESCR_H_
#define __KV_DEV_DESCR_H_

struct dev_descr {
    char *descr_string;
    unsigned int ean[2];
};

static struct dev_descr dev_descr_list[] = {
    { "Kvaser Unknown", { 0x00000000, 0x00000000 } },
    { "Kvaser Virtual CAN", { 0x00000000, 0x00000000 } },
    { "Kvaser Virtual CAN device", { 0x30000000, 0x00073301 } },
    { "Kvaser LAPcan", { 0x30000292, 0x00073301 } },
    { "Kvaser PCcan 4xHS", { 0x30000490, 0x00073301 } },
    { "Kvaser PCcan HS", { 0x30000506, 0x00073301 } },
    { "Kvaser PCcan HS/HS", { 0x30000513, 0x00073301 } },
    { "Kvaser PCIcan-S HS", { 0x30000827, 0x00073301 } },
    { "Kvaser PCIcan HS/HS", { 0x30000834, 0x00073301 } },
    { "Kvaser PCIcan 4xHS", { 0x30000841, 0x00073301 } },
    { "Kvaser LAPcan II", { 0x30001152, 0x00073301 } },
    { "Kvaser PCIcan II S", { 0x30001565, 0x00073301 } },
    { "Kvaser PCIcan II D", { 0x30001572, 0x00073301 } },
    { "Kvaser USBcan II HS (S)", { 0x30001589, 0x00073301 } },
    { "Kvaser USBcan II HS/HS", { 0x30001596, 0x00073301 } },
    { "Kvaser Memorator HS/LS", { 0x30001701, 0x00073301 } },
    { "Kvaser USBcan II HS/LS", { 0x30001749, 0x00073301 } },
    { "Kvaser Memorator HS/HS", { 0x30001756, 0x00073301 } },
    { "Kvaser USBcan Rugged HS", { 0x30001800, 0x00073301 } },
    { "Kvaser USBcan Rugged HS/HS", { 0x30001817, 0x00073301 } },
    { "Kvaser PCIcanP-Swc", { 0x30002210, 0x00073301 } },
    { "Kvaser Amersham opto light RJ45", { 0x30002227, 0x00073301 } },
    { "Kvaser VCI2 Marin", { 0x30002258, 0x00073301 } },
    { "Kvaser USBcan II HS/SWC", { 0x30002319, 0x00073301 } },
    { "Kvaser PCIcanII HSHS Qualstar terminated", { 0x30002333, 0x00073301 } },
    { "Kvaser Memorator HS/SWC", { 0x30002340, 0x00073301 } },
    { "Kvaser Leaf Light HS", { 0x30002418, 0x00073301 } },
    { "Kvaser Leaf SemiPro HS", { 0x30002425, 0x00073301 } },
    { "Kvaser Leaf Professional HS", { 0x30002432, 0x00073301 } },
    { "Kvaser Leaf Light LS", { 0x30002593, 0x00073301 } },
    { "Kvaser Leaf SemiPro LS", { 0x30002609, 0x00073301 } },
    { "Kvaser Leaf Professional LS", { 0x30002616, 0x00073301 } },
    { "Kvaser Leaf Light SWC", { 0x30002623, 0x00073301 } },
    { "Kvaser Leaf SemiPro SWC", { 0x30002630, 0x00073301 } },
    { "Kvaser Leaf Professional SWC", { 0x30002647, 0x00073301 } },
    { "Kvaser Leaf SemiPro LIN", { 0x30002654, 0x00073301 } },
    { "Kvaser Leaf Professional LIN", { 0x30002692, 0x00073301 } },
    { "Kvaser PCIcanx 4xHS", { 0x30003309, 0x00073301 } },
    { "Kvaser PCIcanx HS/HS", { 0x30003316, 0x00073301 } },
    { "Kvaser PCIcanx HS", { 0x30003323, 0x00073301 } },
    { "Kvaser PC104+ HS/HS IDC", { 0x30003361, 0x00073301 } },
    { "Kvaser PCIcanx II HS/HS", { 0x30003439, 0x00073301 } },
    { "Kvaser PCIcanx II HS", { 0x30003446, 0x00073301 } },
    { "Kvaser Memorator Professional HS/HS", { 0x30003514, 0x00073301 } },
    { "Kvaser PC104+ HS/HS", { 0x30003521, 0x00073301 } },
    { "Kvaser USBcan Professional HS/HS", { 0x30003576, 0x00073301 } },
    { "Kvaser PC104+ Special for BAE, OBSOLETE", { 0x30003583, 0x00073301 } },
    { "Kvaser Leaf Light HS (JLT)", { 0x30004009, 0x00073301 } },
    { "Kvaser Leaf Light HS OBDII", { 0x30004023, 0x00073301 } },
    { "Kvaser Leaf SemiPro HS OBDII", { 0x30004030, 0x00073301 } },
    { "Kvaser Leaf Professional HS OBDII", { 0x30004047, 0x00073301 } },
    { "Kvaser PCIEcan HS/HS", { 0x30004054, 0x00073301 } },
    { "Kvaser Leaf Light HS GI", { 0x30004115, 0x00073301 } },
    { "Kvaser USBcan Professional RJ45", { 0x30004139, 0x00073301 } },
    { "Kvaser Memorator Professional HS/LS", { 0x30004177, 0x00073301 } },
    { "Kvaser PCI104 HS/HS IDC", { 0x30004245, 0x00073301 } },
    { "Kvaser PCIEcan HS", { 0x30004252, 0x00073301 } },
    { "Kvaser Leaf Light Rugged HS", { 0x30004276, 0x00073301 } },
    { "Kvaser Leaf Light GI, without cables and housing", { 0x30004283, 0x00073301 } },
    { "Kvaser Leaf Light HS China", { 0x30004351, 0x00073301 } },
    { "Kvaser PCI104 HS/HS", { 0x30004382, 0x00073301 } },
    { "Kvaser BlackBird SemiPro HS", { 0x30004412, 0x00073301 } },
    { "Kvaser BlackBird SemiPro 3xHS", { 0x30004467, 0x00073301 } },
    { "Kvaser BlackBird SemiPro HS/HS", { 0x30004535, 0x00073301 } },
    { "Kvaser BlackBird Professional HS", { 0x30004870, 0x00073301 } },
    { "Kvaser Memorator R SemiPro", { 0x30004900, 0x00073301 } },
    { "Kvaser Leaf SemiPro Rugged HS", { 0x30005068, 0x00073301 } },
    { "Kvaser Leaf Professional Rugged HS", { 0x30005099, 0x00073301 } },
    { "Kvaser Memorator Light HS", { 0x30005136, 0x00073301 } },
    { "Kvaser Leaf Light CB", { 0x30005181, 0x00073301 } },
    { "Kvaser Eagle", { 0x30005679, 0x00073301 } },
    { "Kvaser USBcan Pro SHS/HS", { 0x30005716, 0x00073301 } },
    { "Kvaser USBcan Pro SHS/SHS", { 0x30005723, 0x00073301 } },
    { "Kvaser USBcan R HS/HS", { 0x30005792, 0x00073301 } },
    { "Kvaser Memorator Professional CB", { 0x30005815, 0x00073301 } },
    { "Kvaser BlackBird SemiPro", { 0x30006294, 0x00073301 } },
    { "Scania VCI3", { 0x30006348, 0x00073301 } },
    { "Kvaser Leaf Light J1939-13", { 0x30006423, 0x00073301 } },
    { "Kvaser BlackBird v2", { 0x30006713, 0x00073301 } },
    { "Kvaser BlackBird v2", { 0x30006751, 0x00073301 } },
    { "Kvaser USBcan Pro HS/KLINE", { 0x30006768, 0x00073301 } },
    { "Kvaser PCIEcan 4xHS", { 0x30006829, 0x00073301 } },
    { "Kvaser PCIEcan 4xHS", { 0x30006836, 0x00073301 } },
    { "Kvaser USBcan Professional CB", { 0x30006843, 0x00073301 } },
    { "Kvaser Leaf Light v2", { 0x30006850, 0x00073301 } },
    { "Kvaser Mini PCI Express HS", { 0x30006881, 0x00073301 } },
    { "Kvaser Ethercan Light HS", { 0x30007130, 0x00073301 } },
    { "Kvaser USBcan Light 2xHS", { 0x30007147, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 OBDII", { 0x30007321, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 CB", { 0x30007338, 0x00073301 } },
    { "Kvaser Mini PCI Express 2xHS", { 0x30007437, 0x00073301 } },
    { "Kvaser USBcan Pro 2xHS v2", { 0x30007529, 0x00073301 } },
    { "Kvaser Memorator Pro 5xHS", { 0x30007789, 0x00073301 } },
    { "Kvaser USBcan Pro 5xHS", { 0x30007796, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 J1939-13", { 0x30007871, 0x00073301 } },
    { "Kvaser Memorator Pro 2xHS v2", { 0x30008199, 0x00073301 } },
    { "Kvaser Memorator 2xHS v2", { 0x30008212, 0x00073301 } },
    { "Kvaser USBcan Light 4xHS", { 0x30008311, 0x00073301 } },
    { "Kvaser Memorator Pro 5xHS CB", { 0x30008328, 0x00073301 } },
    { "Kvaser Leaf Pro HS v2", { 0x30008434, 0x00073301 } },
    { "Kvaser Leaf Pro HS v2 OBDII", { 0x30008496, 0x00073301 } },
    { "Kvaser PCIEcan 2xHS v2", { 0x30008618, 0x00073301 } },
    { "Kvaser PCIEcan HS v2", { 0x30008663, 0x00073301 } },
    { "Kvaser Memorator Pro 2xHS v2 CB", { 0x30008694, 0x00073301 } },
    { "Kvaser USBcan Pro 2xHS v2 CB", { 0x30008779, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 M12", { 0x30008816, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 J1939-13 Type II", { 0x30009158, 0x00073301 } },
    { "Kvaser USBcan R v2", { 0x30009202, 0x00073301 } },
    { "Kvaser Leaf Light R v2", { 0x30009219, 0x00073301 } },
    { "Kvaser Hybrid 2xCAN/LIN", { 0x30009653, 0x00073301 } },
    { "Kvaser Ethercan HS", { 0x30009769, 0x00073301 } },
    { "Kvaser BlackBird Pro HS v2", { 0x30009837, 0x00073301 } },
    { "Kvaser Mini PCI Express 2xHS v2", { 0x30010291, 0x00073301 } },
    { "Kvaser Mini PCI Express HS v2", { 0x30010383, 0x00073301 } },
    { "Kvaser Hybrid Pro 2xCAN/LIN", { 0x30010420, 0x00073301 } },
    { "Kvaser Memorator Light HS v2", { 0x30010581, 0x00073301 } },
    { "DIN Rail", { 0x30010598, 0x00073301 } },
    { "Kvaser DIN Rail SE410S", { 0x30011182, 0x00073301 } },
    { "Kvaser U100", { 0x30011731, 0x00073301 } },
    { "Kvaser U100P", { 0x30011748, 0x00073301 } },
    { "Kvaser U100S", { 0x30011816, 0x00073301 } },
    { "Kvaser USBcan Pro 4xHS", { 0x30012615, 0x00073301 } },
    { "Kvaser U100-X1", { 0x30012660, 0x00073301 } },
    { "Kvaser U100-X2", { 0x30012677, 0x00073301 } },
    { "Kvaser U100-X3", { 0x30012684, 0x00073301 } },
    { "Kvaser U100P-X1", { 0x30012691, 0x00073301 } },
    { "Kvaser U100P-X2", { 0x30012707, 0x00073301 } },
    { "Kvaser U100P-X3", { 0x30012714, 0x00073301 } },
    { "Kvaser U100S-X1", { 0x30012721, 0x00073301 } },
    { "Kvaser U100S-X2", { 0x30012738, 0x00073301 } },
    { "Kvaser U100S-X3", { 0x30012745, 0x00073301 } },
    { "Kvaser Hybrid CAN/LIN", { 0x30012844, 0x00073301 } },
    { "Kvaser Hybrid Pro CAN/LIN", { 0x30012882, 0x00073301 } },
    { "Kvaser U100-C", { 0x30013407, 0x00073301 } },
    { "Kvaser Leaf Light GI (Medical)", { 0x30005686, 0x00073301 } },
    { "Kvaser Leaf Light HS v2 OEM", { 0x30007352, 0x00073301 } },
    { "ATI Leaf Light HS v2", { 0x30009493, 0x00073301 } },
    { "ATI USBcan Pro 2xHS v2", { 0x30009691, 0x00073301 } },
    { "ATI Memorator Pro 2xHS v2", { 0x30009714, 0x00073301 } },
    { "Kvaser Leaf v3", { 0x30014244, 0x00073301 } },
    { "Kvaser Leaf v3", { 0x30014268, 0x00073301 } },
    { "Kvaser Leaf v3", { 0x30014282, 0x00073301 } },
    { "Kvaser Leaf v3", { 0x30014305, 0x00073301 } },
    { "Kvaser USBcan Pro 4xCAN Silent", { 0x30014114, 0x00073301 } },
    { "Kvaser PCIEcan 2xCAN v3", { 0x30014329, 0x00073301 } },
    { "Kvaser PCIEcan 1xCAN v3", { 0x30014336, 0x00073301 } },
    { "Kvaser PCIEcan 4xCAN v2", { 0x30014145, 0x00073301 } },
    { "Kvaser Mini PCI Express 2xCAN v3", { 0x30014176, 0x00073301 } },
    { "Kvaser Mini PCI Express 1xCAN v3", { 0x30014206, 0x00073301 } },
};
#endif /* __KV_DEV_DESCR_H_ */
