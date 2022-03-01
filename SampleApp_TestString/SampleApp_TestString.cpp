/* SampleApp_TestString.cpp : This file contains the 'main' function. Program execution begins and ends there.
This file is part of CRCcalculation_Library which is a free software : you can redistribute itand /or modify it under the terms of
the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
CRCcalculation_Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details; https://www.gnu.org/licenses/

https://github.com/tanel312  www.tanels.com  tanel.utilities@gmail.com
*/

#include <iostream>
#include "..\CRCcalculation_Library.h"
#include "..\SupportedTypes.h"

#pragma comment( lib, "C:\\Users\\Tanel\\source\\repos\\CRCcalculation_Library\\Debug\\CRCcalculation_Library.lib" )

extern CRCparameters CRCparams[76];

int main()
{
    unsigned int count = sizeof(CRCparams) / sizeof(CRCparameters);
    uint8_t buf[] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 };
    for (unsigned int i = 0; i < count; i++)
    {
        std::cout << CRCparams[i].name;
        if (CRC_Computation(buf, sizeof(buf) / sizeof(uint8_t), i) == CRCparams[i].check)
            std::cout << " ; *** OK";
        else
            std::cout << " ; !!! NOT MATCH";
        std::cout << "\n";
    }
}
