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

