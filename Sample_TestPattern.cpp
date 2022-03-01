#include <iostream>
#include "CRC.h"

extern polynomial Polynoms[76];

uint64_t CRC_Computation(uint8_t* Input, uint64_t Length, uint8_t Type);

int main()
{
    unsigned int count = sizeof(Polynoms) / sizeof(polynomial);
    uint8_t buf[9] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 };
    for (unsigned int i = 0; i < count; i++)
    {
        std::cout << Polynoms[i].name;
        if (CRC_Computation(buf, 9, i) == Polynoms[i].check)
            std::cout << " ; *** OK";
        else
            std::cout << " ; !!! NOT MATCH";
        std::cout << "\n";
    }
}
