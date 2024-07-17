# eis

## Setup 
To set up the library, navigate into the folder and execute the python file **setup.py**

```
cd ./eis
python3 setup.py
```

This will add the two libraries **pybind11** and **google test**. The library will then be built, and the unit tests will be carried out. 
If the libraries already exist, executing the file will update them instead of downloading them again.


## Description 
The eis (Error Insertion Simulator) library simulates bit flips in Floating Point Numbers (FPNs). It is a stripped-down version of my mps (Multi Precision Simulator) library with small additions to be able to introduce bit flips. Bit flips can easily be simulated using the library, as depicted in the listing below. Furthermore, it can easily be integrated into Python code since everything can be converted into a Python library using pybind11.

```
import eis_library as eis

mantissa_length = 52
exponent_length = 11
value = 3.14

value_eis = eis(mantissa_length, exponent_length)
value_eis.value = value 
value_eis.flip_mantissa(23)

value = value_eis.value
```

The first line is easy, as it imports the created Python library. Afterwards, three variables are initialized. First, the size of the *mantissa* and the *exponent* must be defined. Secondly, the original value must be set. Next, the eis object is initialized. It needs the previously defined sizes of the $mantissa$ and the $exponent$ since, in the next step, it will convert the whole number into an FPN with those specifications. A bit can be flipped after the object is set to a value. In the case of Listing from above, the *mantissa* bit with the index $23$ (indexing stars from $0$) is flipped. This alters the value of the simulated FPN, so when the number is converted back to a decimal number in the last line, the new value will be the old value plus an error.

The conversion into this simulated FPN can also introduce an additional error, which is the case if the defined sizes of the *mantissa* and the *exponent* are smaller than the ones used by the system. To void such an error in Python, a minimum *mantissa* size of $52$ and a minimum *exponent* size of $11$ should be used since Python internally represents FPNs in the *double* format. Nevertheless, such a mechanism is not necessarily a bad thing since that way the accuracy of the FP format can be artificially reduced. In this context, it is very similar to the method of Higham and Pranesh, which can be found in the following source:

- Nicholas J. Higham and Srikara Pranesh. “Simulating Low Precision Floating-Point Arithmetic”. In: SIAM Journal on Scientific Computing 41.5 (Jan. 2019). Publisher: Society for Industrial and Applied Mathematics, pp. C585–C602. issn: 1064-8275.

