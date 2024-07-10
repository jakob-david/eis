# eis

## Setup 
To setup the library just navigate into the folder and execute the python file **setup.py**

```
cd ./eis
python3 setup.py
```

This will add the two libraries **pybind11** and **google test **. The library will then be built, and the unit tests will be carried out. 
If the libraries do already exist, an execution of the file will update the libraries instead of updating them again.


## Description 
Bit flips can be simulated in many ways, but in this project, they are simulated using the eis (Error Insertion Simulator) library, which is a self-written library in C++. More specifically, it is a stripped-down version of the mps (Multi Precision Simulator) library with small additional changes to be able to introduce bit flips. A bit flip can easily be simulated as is depicted in the listing below. It can easily used inside Python since the code can be converted into a Python library using pybind11.

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

The first line is easy, as it just imports the created Python library. Please note that the project might contain an EIS library file, but it will most likely need to be compiled for each machine individually. Afterwards, three variables are initialized. First, the size of the *mantissa* and the *exponent* must be defined. Secondly, the original value must also be set. Next, the eis object is initialized. It needs the previously defined sizes of the $mantissa$ and the $exponent$ since it is converting the whole number into three-bit arrays ($s$, $e$, and $m$ as defined previously) in the next step. A bit can be flipped after the object is initialized with a value. In the case of Listing from above, the *mantissa* bit with the index $23$ (indexing stars from $0$) is flipped. This obviously alters the value of the simulated FPN, so when the number is converted back to a decimal number in the last line, this new value will also be altered.

Please note that the conversion into this simulated FPN can also introduce an additional error. This is the case if the defined sizes of *mantissa* and *exponent* are smaller than the system's. Therefore, for the whole of the project, a *mantissa* size of $52$ and an *exponent* size of $21$ will be used since this represents the *double* format that Python uses for storing FPNs. However, be aware that such a mechanism is not necessarily a bad thing since the accuracy of the FP format can be artificially reduced that way. In this context, it is very similar to the method of Higham and Pranesh which can be found in the following source:

- Nicholas J. Higham and Srikara Pranesh. “Simulating Low Precision Floating-Point Arithmetic”. In: SIAM Journal on Scientific Computing 41.5 (Jan. 2019). Publisher: Society for Industrial and Applied Mathematics, pp. C585–C602. issn: 1064-8275.

