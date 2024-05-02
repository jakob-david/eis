//
// Created by Jakob on 02.05.24.
//

#ifndef EIS_EIS_H
#define EIS_EIS_H

#include <vector>


class eis {

private:

    // properties of the bit array
    //-------------------------------
    unsigned long mantissa_length;    // The length of the mantissa of the bit array.
    unsigned long exponent_length;    // The length of the exponent of the bit array.
    //-------------------------------

    // bits for binary FP representation
    //-------------------------------
    bool sign = false;
    std::vector<bool> exponent;
    std::vector<bool> mantissa;
    //-------------------------------

public:

    // constructors and destructor
    //-------------------------------
    eis(unsigned long mantissa_length, unsigned long exponent_length);
    ~eis() = default;
    //-------------------------------

    // setter and getter
    //-------------------------------
    void setSign(const bool new_sign);

    bool getSign() const;
    //-------------------------------

};


#endif //EIS_EIS_H
