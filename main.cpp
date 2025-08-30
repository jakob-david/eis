#include <iostream>

#include "eis/eis.h"

using namespace std; 



int main() {
    
    eis EIS(26, 9);

    EIS.setValue(3.14); 
    cout << "Original Value: " << "\t" << EIS.getValue() << endl; 

    EIS.flipSign(); 
    EIS.flipExponent(4); 
    EIS.flipMantissa(20); 

    cout << "Value after Flips: " << "\t" << EIS.getValue() << endl; 

    return 0;
}
