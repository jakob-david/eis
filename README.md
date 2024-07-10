# EIS

Bit flips can be simulated in many ways, but in this project, they are simulated using the EIS (Error Insertion Simulator) library, which is a self-written library in C++. More specifically, it is a stripped-down version of the MPS (Multi Precision Simulator) library with small additional changes to be able to introduce bit flips. A bit flip can easily be simulated as is depicted in Listing \ref{using_eis_library}. It can easily used inside Python since the code can be converted into a Python library using pybind11

