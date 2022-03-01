/*This file is part of CRCcalculation_Library which is a free software : you can redistribute itand /or modify it under the terms of 
the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
CRCcalculation_Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details; https://www.gnu.org/licenses/

https://github.com/tanel312  www.tanels.com  tanel.utilities@gmail.com
*/
#pragma once

// structure of CRC parameters
typedef struct _crcparam
{
    uint8_t width;
    uint64_t normal;
    uint64_t initial;
    bool initialrefl;
    bool reflected;
    uint64_t xorout;
    uint64_t check;
    uint64_t residue;
    const char name[26];
} CRCparameters;

// Reflects the input(mirroring)
void Reflect(
    uint64_t* Inp, // input/output; value to be reflected
    uint8_t Width); // input; width of value in bits

// Creates CRC Lookup Table
void CreateCRCtable(
    uint64_t* CrcTable, // output; CRC lookup table, array of 256 cells
    uint64_t Polynomial, // input; normal polnomial
    uint8_t Width); // width of CRC in bits

// Creates CRC Reflected Lookup Table
void CreateCRCtableReflected(
    uint64_t* CrcTable, // output; CRC Reflected lookup table, array of 256 cells
    uint64_t Polynomial, // input; normal polnomial (not reflected)
    uint8_t Width); //  input; width of CRC in bits

// Calculates the CRC iaw selected type
uint64_t CalculateCRC(
    uint8_t* Buffer, // input; input data
    uint64_t Length, // input; length of input data in bytes
    uint64_t* CrcTable, // input; CRC Lookup table
    uint8_t Width, // input; width of CRC in bits
    uint64_t Initialcrc, // input; inital XOR value
    bool Initialrefl, // input; whether inital XOR value to be reflected
    uint64_t XORout); // input; final XOR value

// Calculates the reflected CRC iaw selected type
uint64_t CalculateCRCreflected(
    uint8_t* Buffer, // input; input data
    uint64_t Length, // input; length of input data in bytes
    uint64_t* CrcTable, // input; CRC Reflected Lookup table
    uint8_t Width, // input; width of CRC in bits
    uint64_t Initialcrc, // input; inital XOR value
    bool Initialrefl, // input; whether inital XOR value to be reflected
    uint64_t XORout); // input; final XOR value

// Main function to be called to calculate the CRC of input data iaw the selected type. CRC returned as unsigned long long integer
uint64_t CRC_Computation(
    uint8_t* Input, // input; data array of byte
    uint64_t Length, // input; length of input buffer in bytes
    uint8_t Type); // input; type of CRC, supported types listed in SupportedTypes.h

