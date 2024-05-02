//
// Created by Jakob on 02.05.24.
//

#include "gtest/gtest.h"
#include "eis.h"

TEST(constructor, simple_1){

    unsigned long mantissa_length = 23;
    unsigned long exponent_length = 8;

    eis EIS(mantissa_length, exponent_length);

    EXPECT_EQ(mantissa_length, EIS.getMantissaLength());
    EXPECT_EQ(exponent_length, EIS.getExponentLength());
    EXPECT_EQ(mantissa_length, EIS.getMantissa().size());
    EXPECT_EQ(exponent_length, EIS.getExponent().size());
}

TEST(setter_getter, simple_1){

    unsigned long mantissa_length = 52;
    unsigned long exponent_length = 11;

    unsigned long new_mantissa_length = 23;
    unsigned long new_exponent_length = 8;

    eis EIS(mantissa_length, exponent_length);

    std::vector<bool> new_mantissa;
    new_mantissa.resize(new_mantissa_length, false);
    std::vector<bool> new_exponent;
    new_exponent.resize(new_exponent_length, false);

    EIS.setSign(true);
    EIS.setMantissa(new_mantissa);
    EIS.setExponent(new_exponent);

    EXPECT_EQ(new_mantissa_length, EIS.getMantissaLength());
    EXPECT_EQ(new_exponent_length, EIS.getExponentLength());
    EXPECT_EQ(new_mantissa_length, EIS.getMantissa().size());
    EXPECT_EQ(new_exponent_length, EIS.getExponent().size());

    for(auto element : EIS.getExponent()){
        EXPECT_FALSE(element);
    }

    for(auto element : EIS.getExponent()){
        EXPECT_FALSE(element);
    }
}

TEST(flippers, simple_1){

    unsigned long flipped_mantissa_bit = 23;
    unsigned long flipped_exponent_bit = 6;

    unsigned long mantissa_length = 52;
    unsigned long exponent_length = 11;
    unsigned long new_mantissa_length = 23;
    unsigned long new_exponent_length = 8;

    eis EIS(mantissa_length, exponent_length);

    std::vector<bool> new_mantissa;
    new_mantissa.resize(new_mantissa_length, false);
    std::vector<bool> new_exponent;
    new_exponent.resize(new_exponent_length, false);

    EIS.setSign(false);
    EIS.setMantissa(new_mantissa);
    EIS.setExponent(new_exponent);

    EIS.flipSign();
    EIS.flipMantissa(flipped_mantissa_bit);
    EIS.flipExponent(flipped_exponent_bit);


    // examine sign
    EXPECT_TRUE(EIS.getSign());

    // examine mantissa
    auto mantissa = EIS.getMantissa();
    for(unsigned long idx = 0; idx < mantissa.size(); idx++){

        if(idx == flipped_mantissa_bit){
            EXPECT_TRUE(mantissa[idx]);
        } else {
            EXPECT_FALSE(mantissa[idx]);
        }
    }

    // examine exponent
    auto exponent = EIS.getExponent();
    for(unsigned long idx = 0; idx < exponent.size(); idx++){

        if(idx == flipped_exponent_bit){
            EXPECT_TRUE(exponent[idx]);
        } else {
            EXPECT_FALSE(exponent[idx]);
        }
    }
}