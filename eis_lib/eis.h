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
    void setSign(bool new_sign);
    void setExponent(const std::vector<bool>& new_exponent);
    void setMantissa(const std::vector<bool>& new_mantissa);

    [[nodiscard]] bool getSign() const;
    [[nodiscard]] std::vector<bool> getExponent() const;
    [[nodiscard]] std::vector<bool> getMantissa() const;
    [[nodiscard]] std::vector<bool> getBitArray() const;
    [[nodiscard]] unsigned long getExponentLength() const;
    [[nodiscard]] unsigned long getMantissaLength() const;
    //-------------------------------

    // special values
    //-------------------------------
    void setNaN(bool negative = false);
    void setInf(bool negative = false);
    void setZero(bool negative = false);

    [[nodiscard]] bool isNaN() const;
    [[nodiscard]] bool isInf() const;
    [[nodiscard]] bool isZero() const;
    [[nodiscard]] bool isPositive() const;
    //-------------------------------

    // flippers
    //-------------------------------
    void flipSign();
    void flipExponent(unsigned long idx);
    void flipMantissa(unsigned long idx);
    //-------------------------------

    // convert value
    //-------------------------------
    void setValue(long double new_value);

    [[nodiscard]] long double getValue() const;
    //-------------------------------

    // to string
    //-------------------------------
    [[nodiscard]] std::string toString() const;
    //-------------------------------

private:

    // helper functions
    //-------------------------------
    [[nodiscard]] long getBias() const;
    [[nodiscard]] static bool allTrue(const std::vector<bool>& vector);
    //-------------------------------

};


#endif //EIS_EIS_H
