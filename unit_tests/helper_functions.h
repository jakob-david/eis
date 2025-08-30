//
// Created by Jakob on 02.05.24.
//

#ifndef EIS_FUNCTIONS_H
#define EIS_FUNCTIONS_H

#include <bitset>

template <typename T>
inline std::string printBitArray(T fp_number){

    std::string compare_str;
    char* bits = reinterpret_cast<char*>(&fp_number);
    for(unsigned long n = 0; n < sizeof fp_number; ++n) {
        std::string tmp = std::bitset<8>((unsigned long long) bits[n]).to_string();
        compare_str.insert (0, tmp);
    }

    return  compare_str;
}

#endif //EIS_FUNCTIONS_H
