# CRCcalculation_Library
CRC calculation library for 8-bit, 16-bit, 24-bit, 32-bit, 40-bit and 64 bit. Supports 76 CRC types

CRC Calculation Library provides functionality to compute Cyclic Redundancy Check (CRC) value of input data 
in the size of upto 2^64 bytes (theoratically). It supports CRC types with width in multiplier of 8-bits. 
Predefined CRC types are listed below; 

- CRC-8/AUTOSAR
- CRC-8/BLUETOOTH
- CRC-8/CDMA2000
- CRC-8/DARC
- CRC-8/DVB-S2
- CRC-8/GSM-A
- CRC-8/GSM-B
- CRC-8/HITAG
- CRC-8/I-432-1
- CRC-8/I-CODE
- CRC-8/LTE
- CRC-8/MAXIM-DOW
- CRC-8/MIFARE-MAD
- CRC-8/NRSC-5
- CRC-8/OPENSAFETY
- CRC-8/ROHC
- CRC-8/SAE-J1850
- CRC-8/SMBUS			
- CRC-8/TECH-3250 
- CRC-8/WCDMA 
- CRC-16/ARC 
- CRC-16/CDMA2000 
- CRC-16/CMS 
- CRC-16/DDS-110 
- CRC-16/DECT-R 
- CRC-16/DECT-X 
- CRC-16/DNP 
- CRC-16/EN-13757 
- CRC-16/GENIBUS 
- CRC-16/GSM 
- CRC-16/IBM-3740 
- CRC-16/IBM-SDLC 
- CRC-16/ISO-IEC-14443-3-A
- CRC-16/KERMIT 
- CRC-16/LJ1200 
- CRC-16/MAXIM-DOW 
- CRC-16/MCRF4XX 
- CRC-16/MODBUS 
- CRC-16/NRSC-5 
- CRC-16/OPENSAFETY-A 
- CRC-16/OPENSAFETY-B 
- CRC-16/PROFIBUS 
- CRC-16/RIELLO 
- CRC-16/SPI-FUJITSU 
- CRC-16/T10-DIF 
- CRC-16/TELEDISK 
- CRC-16/TMS37157 
- CRC-16/UMTS 
- CRC-16/USB 
- CRC-16/XMODEM 
- CRC-24/BLE 
- CRC-24/FLEXRAY-A 
- CRC-24/FLEXRAY-B 
- CRC-24/INTERLAKEN 
- CRC-24/LTE-A 
- CRC-24/LTE-B 
- CRC-24/OPENPGP 
- CRC-24/OS-9 
- CRC-32/AIXM 
- CRC-32/AUTOSAR 
- CRC-32/BASE91-D 
- CRC-32/BZIP2 
- CRC-32/CD-ROM-EDC 
- CRC-32/CKSUM 
- CRC-32/ISCSI 
- CRC-32/ISO-HDLC 
- CRC-32/JAMCRC 
- CRC-32/MEF 
- CRC-32/MPEG-2 
- CRC-32/XFER 
- CRC-40/GSM 
- CRC-64/ECMA-182 
- CRC-64/GO-ISO 
- CRC-64/MS 
- CRC-64/WE 
- CRC-64/XZ 

A sample console application; SampleApp_TestString is provided. It calculates CRCs for famous "123456789" string 
in supported 76 types and compares the result with known value.

The header files listed below are provided to use library;

CRCcalculation_Library.h includes; (required)
- a data structure definition if any CRC parameter is needed to be accessed by an application.
- prototypes of functions in the library.

SupportedTypes.h includes list of supported CRC types. (required)

ListOfPolynomials.h includes parameters of all supported CRC types. (if necessary)

/*This file is part of CRCcalculation_Library which is a free software : you can redistribute itand /or modify it under the terms of 
the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
CRCcalculation_Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details. 
You should have received a copy of the GNU General Public License along with Foobar.If not, see < https://www.gnu.org/licenses/>.
*/
