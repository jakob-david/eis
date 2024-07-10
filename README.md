# EIS

Bit flips can be simulated in many ways, but in this project, they are simulated using the EIS (Error Insertion Simulator) library, which is a self-written library in C++. More specifically, it is a stripped-down version of the MPS (Multi Precision Simulator) library with small additional changes to be able to introduce bit flips. A bit flip can easily be simulated as is depicted in the listing below. It can easily used inside Python since the code can be converted into a Python library using pybind11.

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

The first line is easy, as it just imports the created Python library. Please note that the project might contain an EIS library file, but it will most likely need to be compiled for each machine individually. Afterwards, three variables are initialized. First, the size of the \textit{mantissa} and the \textit{exponent} must be defined. Secondly, the original value must also be set. Next, the EIS object is initialized. It needs the previously defined sizes of the $mantissa$ and the $exponent$ since it is converting the whole number into three-bit arrays ($s$, $e$, and $m$ as defined previously) in the next step. A bit can be flipped after the object is initialized with a value. In the case of Listing \ref{using_eis_library}, the \textit{mantissa} bit with the index $23$ (indexing stars from $0$) is flipped. This obviously alters the value of the simulated FPN, so when the number is converted back to a decimal number in the last line, this new value will also be altered.\

