//
// Created by Jakob on 02.05.24.
//

#include "eis.h"


// constructors and destructor
//-------------------------------
eis::eis(unsigned long mantissa_length, unsigned long exponent_length){

    this->mantissa_length = mantissa_length;
    this->exponent_length = exponent_length;

    this->mantissa.resize(mantissa_length);
    this->exponent.resize(exponent_length);
}
//-------------------------------


// setter and getter
//-------------------------------
void eis::setSign(const bool new_sign) {
    this->sign = new_sign;
}

bool eis::getSign() const {
    return this->sign;
}
//-------------------------------