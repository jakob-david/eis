import os

print("setup pybind11 library")
if os.path.exists("./pybind11"):
    os.system("git -C ./pybind11 pull")
else:
    os.system("mkdir ./pybind11")
    os.system("git clone https://github.com/pybind/pybind11.git ./pybind11")

print("setup googletest library")
if os.path.exists("./gtests/googletest"):
    os.system("git -C ./pybind11 pull")
else:
    os.system("mkdir ./gtests/googletest")
    os.system("git clone https://github.com/google/googletest.git ./gtests/googletest")

print("create build directory")
if not os.path.exists("./gtests/googletest"):
    os.system("mkdir ./build")

# create build files
os.system("cmake -S ./ -B ./build")

# build library and run unit tests
os.system("cmake --build ./build && ./build/gtests/eis_tests")
