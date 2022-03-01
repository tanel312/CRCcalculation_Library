/* CRCcalculation_Library.cpp : Defines the functions for the static library.

This file is part of CRCcalculation_Library which is a free software : you can redistribute itand /or modify it under the terms of 
the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
CRCcalculation_Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty 

https://github.com/tanel312  www.tanels.com  tanel.utilities@gmail.com
*/

#include "pch.h"
#include "framework.h"

#include "CRCcalculation_Library.h"
#include "ListOfPolynomials.h"

// Mode can be one of followings;
#define CRC8 0
#define CRC16 1
#define CRC24 2
#define CRC32 3
#define CRC40 4
#define CRC64 7

uint64_t const Mask[8] = { 0xFF, 0xFFFF, 0xFFFFFF, 0xFFFFFFFF, 0xFFFFFFFFFF, 0, 0, 0xFFFFFFFFFFFFFFFF };
uint64_t const Msbcheck[8] = { 0x80, 0x8000, 0x800000, 0x80000000, 0x8000000000, 0, 0, 0x8000000000000000 };
uint8_t const Shifter[8] = { 0, 8, 16, 24, 32, 0, 0, 56 };

/*-------------------------------------------------------------------------------
  Reflect
  Reflects the input (mirroring)
  Inputs: Width
  Input/Output: Inp
-------------------------------------------------------------------------------*/
void Reflect(uint64_t* Inp, uint8_t Width)
{
    uint64_t tmp = ((uint64_t)Width / 8) - 1;
    uint64_t mask = Msbcheck[tmp];
    tmp = *Inp;
    *Inp = 0;
    while (Width--)
    {
        if (tmp & 1L)
            *Inp |= mask;
        tmp >>= 1;
        mask >>= 1;
    }
    return;
}
/*-------------------------------------------------------------------------------
  CreateCRCtable
  Creates CRC Lookup Table
  Inputs: Polynomial, Width
  Output: CrcTable
-------------------------------------------------------------------------------*/
void CreateCRCtable(uint64_t* CrcTable, uint64_t Polynomial, uint8_t Width)
{
    uint64_t index;
    uint64_t value;
    uint8_t cnt;
    uint8_t mode = Width / 8 - 1;

    for (index = 0; index < 256; index++)
    {
        value = ((index << Shifter[mode]) & Mask[mode]);
        cnt = 8;
        while (cnt--)
        {
            value = ((value & Msbcheck[mode]) == 0) ? (value << 1) : (value << 1) ^ Polynomial;
            value &= Mask[mode];
        }
        CrcTable[index] = value;
    }
}
/*-------------------------------------------------------------------------------
  CreateCRCtableReflected
  Creates CRC Reflected Lookup Table
  Inputs: Polynomial, Width
  Output: CrcTable
-------------------------------------------------------------------------------*/
void CreateCRCtableReflected(uint64_t* CrcTable, uint64_t Polynomial, uint8_t Width)
{
    uint64_t index;
    uint64_t value, tmp;
    uint8_t cnt;
    uint8_t mode = Width / 8 - 1;
    uint64_t polynomalR = Polynomial;
    Reflect(&polynomalR, Width);
    for (index = 0; index < 256; index++)
    {
        value = 0;
        tmp = index;
        cnt = 8;
        while (cnt--)
        {
            value = (((value ^ tmp) & 0x1) == 0) ? (value >> 1) : (value >> 1) ^ polynomalR;
            value &= Mask[mode];
            tmp >>= 1;
        }
        CrcTable[index] = value;
    }
    return;
}
/*-------------------------------------------------------------------------------
  CalculateCRC
  Calculates the CRC iaw selected type
  Inputs: Buffer, Length, CrcTable, Width, Initialcrc, Initialrefl, XORout
  Output: function returns
-------------------------------------------------------------------------------*/
uint64_t CalculateCRC(uint8_t* Buffer, uint64_t Length, uint64_t* CrcTable, uint8_t Width, uint64_t Initialcrc, bool Initialrefl, uint64_t XORout)
{
    uint64_t crc = Initialcrc;
    if (Initialrefl)
        Reflect(&crc, Width);
    uint8_t mode = Width / 8 - 1;
    uint8_t index;
    while (Length--)
    {
        index = (uint8_t)((crc >> Shifter[mode]) ^ *Buffer++);
        crc = (mode == CRC8) ? (CrcTable[index]) : ((crc << 8) ^ CrcTable[index]);
    }
    return ((crc ^ XORout) & Mask[mode]);
}
/*-------------------------------------------------------------------------------
  CalculateCRCreflected
  Calculates the reflected CRC iaw selected type
  Inputs: Buffer, Length, CrcTable, Width, Initialcrc, Initialrefl, XORout
  Output: function returns
-------------------------------------------------------------------------------*/
uint64_t CalculateCRCreflected(uint8_t* Buffer, uint64_t Length, uint64_t* CrcTable, uint8_t Width, uint64_t Initialcrc, bool Initialrefl, uint64_t XORout)
{
    uint64_t crc = Initialcrc;
    if (Initialrefl)
        Reflect(&crc, Width);
    uint8_t mode = Width / 8 - 1;
    while (Length--)
    {
        crc = (crc >> 8) ^ CrcTable[(crc ^ *Buffer++) & Mask[CRC8]];
    }
    return((crc ^ XORout) & Mask[mode]);
}
/*-------------------------------------------------------------------------------
  CRC_Computation
  Main function of CRC calculation library
  Inputs: Input, Length, Type
  Output: function
-------------------------------------------------------------------------------*/
uint64_t CRC_Computation(uint8_t* Input, uint64_t Length, uint8_t Type)
{
    uint64_t crc;
    uint64_t crctable[256];

    if (CRCparams[Type].reflected == false)
    {
        // normal crc 
        CreateCRCtable(crctable, CRCparams[Type].normal, CRCparams[Type].width);
        crc = CalculateCRC(Input, Length, crctable, CRCparams[Type].width, CRCparams[Type].initial, CRCparams[Type].initialrefl, CRCparams[Type].xorout);
    }
    else
    {
        // reflected crc
        CreateCRCtableReflected(crctable, CRCparams[Type].normal, CRCparams[Type].width);
        crc = CalculateCRCreflected(Input, Length, crctable, CRCparams[Type].width, CRCparams[Type].initial, CRCparams[Type].initialrefl, CRCparams[Type].xorout);
    }
    return crc;
}
