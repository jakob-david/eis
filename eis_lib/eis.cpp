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

void eis::setExponent(const std::vector<bool>& new_exponent) {

    if(new_exponent.size() != this->exponent_length){
        this->exponent.resize(new_exponent.size());
        this->exponent_length = new_exponent.size();
    }

    for(unsigned long idx = 0; idx < new_exponent.size(); idx++){
        this->exponent[idx] = new_exponent[idx];
    }
}

void eis::setMantissa(const std::vector<bool>& new_mantissa) {

    if(new_mantissa.size() != this->mantissa_length){
        this->mantissa.resize(new_mantissa.size());
        this->mantissa_length = new_mantissa.size();
    }

    for(unsigned long idx = 0; idx < new_mantissa.size(); idx++){
        this->mantissa[idx] = new_mantissa[idx];
    }
}



bool eis::getSign() const {
    return this->sign;
}

std::vector<bool> eis::getExponent() const {
    return this->exponent;
}

std::vector<bool> eis::getMantissa() const {
    return this->mantissa;
}

unsigned long eis::getExponentLength() const {
    return this->exponent_length;
}

unsigned long eis::getMantissaLength() const {
    return this->mantissa_length;
}
//-------------------------------


// flippers
//-------------------------------
void eis::flipSign() {
    this->sign = not this->sign;
}

void eis::flipExponent(unsigned long idx) {
    this->exponent[idx] = not this->exponent[idx];
}

void eis::flipMantissa(unsigned long idx) {
    this->mantissa[idx] = not this->mantissa[idx];
}
//-------------------------------