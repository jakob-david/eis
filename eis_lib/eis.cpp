//
// Created by Jakob on 02.05.24.
//

#include "eis.h"


// constructors and destructor
//-------------------------------
eis::eis(unsigned long mantissa_length, unsigned long exponent_length){

    this->mantissa_length = mantissa_length;
    this->exponent_length = exponent_length;

    this->mantissa.resize(mantissa_length, false);
    this->exponent.resize(exponent_length, false);
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

std::vector<bool> eis::getBitArray() const {

    std::vector<bool> ret;
    ret.reserve(1 + this->exponent_length + this->mantissa_length);

    ret.push_back(this->sign);
    ret.insert(ret.end(), this->exponent.begin(), this->exponent.end());
    ret.insert(ret.end(), this->mantissa.begin(), this->mantissa.end());

    return ret;
}

unsigned long eis::getExponentLength() const {
    return this->exponent_length;
}

unsigned long eis::getMantissaLength() const {
    return this->mantissa_length;
}
//-------------------------------


// special values
//-------------------------------
void eis::setNaN(bool negative){

    if( this->exponent.empty() || this->mantissa.empty()){
        this->exponent.resize(this->exponent_length);
        this->mantissa.resize(this->exponent_length);
    }

    if(negative){
        this->sign = true;
    } else {
        this->sign = false;
    }

    for(unsigned long i = 0; i < this->exponent_length; i++){
        this->exponent[i] = true;
    }

    this->mantissa[0] = true;
    for(unsigned long i = 1; i < this->mantissa_length; i++){
        this->mantissa[i] = false;
    }
}

void eis::setInf(bool negative) {

    if( this->exponent.empty() || this->mantissa.empty()){
        this->exponent.resize(this->exponent_length);
        this->mantissa.resize(this->exponent_length);
    }

    if(negative){
        this->sign = true;
    } else {
        this->sign = false;
    }

    for(unsigned long i = 0; i < this->exponent_length; i++){
        this->exponent[i] = true;
    }

    for(unsigned long i = 0; i < this->mantissa_length; i++){
        this->mantissa[i] = false;
    }
}

void eis::setZero(bool negative){

    if( (this->exponent.size() != this->exponent_length) || (this->mantissa.size() != this->mantissa_length)){
        this->exponent.resize(this->exponent_length);
        this->mantissa.resize(this->mantissa_length);
    }

    this->sign = negative;

    for(unsigned long i = 0; i < this->exponent_length; i++){
        this->exponent[i] = false;
    }
    for(unsigned long i = 0; i < this->mantissa_length; i++){
        this->mantissa[i] = false;
    }
}



bool eis::isZero() const {

    for(unsigned long i = 0; i < this->exponent_length; i++){
        if(this->exponent[i]){
            return false;
        }
    }

    for(unsigned long i = 0; i < this->mantissa_length; i++){
        if(this->mantissa[i]){
            return false;
        }
    }

    return true;
}

bool eis::isNaN() const {

    for(unsigned long i = 0; i < this->exponent_length; i++){

        if(not this->exponent[i]){
            return false;
        }
    }

    if(not this->mantissa[0]){
        return false;
    }

    for(unsigned long i = 1; i < this->mantissa_length; i++){

        if(this->mantissa[i]){
            return false;
        }
    }

    return true ;
}

bool eis::isInf() const {


    for(unsigned long i = 0; i < this->exponent_length; i++){
        if(not this->exponent[i]){
            return false;
        }
    }

    for(unsigned long i = 0; i < this->mantissa_length; i++){
        if(this->mantissa[i]){
            return false;
        }
    }

    return true;
}

bool eis::isPositive() const{

    if(this->sign){
        return false;
    } else {
        return true;
    }
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


// set and get bit array value
//-------------------------------
void eis::setValue(long double new_value) {

    // Handle special values.
    //-------------------------------
    if(0 == new_value){
        this->setZero(); return;
    } else if(std::numeric_limits<long double>::infinity() == new_value) {
        this->setInf(); return;
    } else if (std::numeric_limits<long double>::infinity() * -1 == new_value){
        this->setInf(true); return;
    } else if (isnan(new_value)){
        if(signbit(new_value)){
            this->setNaN(true);
        } else {
            this->setNaN();
        }
        return;
    }
    //-------------------------------

    // prepare vectors
    //-------------------------------
    this->exponent.clear();
    this->mantissa.clear();
    //-------------------------------


    // set sign
    //-------------------------------
    this->sign = new_value <= 0;
    //-------------------------------


    // exponent
    //-------------------------------
    // calculate the exponent
    long long mantissa_shift;
    if(abs(new_value) > std::numeric_limits<float>::max()){
        // When the value is too large rounding problems occur using log2.
        // (At least I think that is the problem)
        long double tmp_value = abs(new_value);
        long tmp_count = 0;

        while(tmp_value >= 1){
            tmp_value /= 2;
            tmp_count++;
        }
        mantissa_shift = tmp_count-1;
    } else {
        mantissa_shift = (long long) floor(log2(abs(new_value)));
    }

    // Getting the exponent in binary format.
    // The sign is not relevant. Always returns a "positive" value.
    for(auto i = mantissa_shift + this->getBias(); i > 0; i /= 2){
        this->exponent.insert(this->exponent.begin(), i % 2);
    }

    bool value_too_large = false;
    if(this->exponent.size() > this->exponent_length){
        value_too_large = true;
    } else if(this->exponent.size() == this->exponent_length){
        value_too_large = eis::allTrue(this->exponent);
    }
    // Fill not used but available bits with zero.
    if  (value_too_large){

        this->exponent.resize(this->exponent_length);
        this->mantissa.resize(this->mantissa_length);

        if(new_value > 0){
            this->setInf();
        } else {
            this->setInf(true);
        }

        return;

    } else {
        this->exponent.insert(this->exponent.begin(), this->exponent_length-this->exponent.size(), false);
    }
    //-------------------------------


    // mantissa
    //-------------------------------
    // adjust the value so that everything is behind the decimal point.
    auto tmp_value = new_value / pow(2, mantissa_shift);

    // Convert the part after the decimal point to a bit string.
    // The sign is not relevant. Always returns a "positive" value.
    long double reminder = abs(tmp_value) - floor(abs(tmp_value));
    for(unsigned long i = 0; i < this->mantissa_length; i++){

        reminder *= 2;
        if(reminder >= 1){
            this->mantissa.push_back(true); reminder -= 1;
        } else{
            this->mantissa.push_back(false);
        }
    }
    //-------------------------------

}

long double eis::getValue() const {

    // handle special cases
    if(this->isZero()){
        return 0;
    } else if (this->isInf() && this->isPositive()){
        return std::numeric_limits<long double>::infinity();
    } else if (this->isInf()){
        return std::numeric_limits<long double>::infinity() * -1;
    } else if (this->isNaN()){
        return std::numeric_limits<long double>::quiet_NaN();
    }


    double ret;

    // positive or negative
    if(this->sign){
        ret = -1;
    } else {
        ret = 1;
    }

    // handle mantissa
    for(unsigned long i = 0; i < this->mantissa_length; i++){
        if(this->mantissa[i]){
            if(ret >= 0){
                ret += pow(0.5, i + 1);
            } else {
                ret -= pow(0.5, i + 1);
            }
        }
    }

    // get exponent
    long exp = 0;
    for(unsigned long i = 0; i < this->exponent_length; i++){
        if(this->exponent[i]){
            exp += (long) pow(2, this->exponent_length-i-1);
        }
    }

    // apply bias and apply exponent
    exp -= this->getBias();

    return ret * pow(2, exp);
}
//-------------------------------


// to string
//-------------------------------
std::string eis::toString() const{

    std::string str;
    for(bool bit : this->getBitArray()){
        if(bit){
            str.append("1");
        } else {
            str.append("0");
        }
    }

    return str;
}
//-------------------------------


// helper functions
//-------------------------------
long eis::getBias() const{
    return ((long) pow (2, exponent_length)) / 2 -1;
}

[[nodiscard]] bool eis::allTrue(const std::vector<bool>& vector) {
    return std::all_of(vector.begin(), vector.end(), [](bool i){return i;});
}
//-------------------------------