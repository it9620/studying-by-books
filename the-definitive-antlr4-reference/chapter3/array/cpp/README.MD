# README

To build:

```sh
# For Debug build:
mkdir build && cd build &&
conan install .. --build=missing -s build_type=Debug -s compiler=clang -s compiler.version=15 &&
cmake .. -DCMAKE_TOOLCHAIN_FILE=Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 &&
cmake --build . 
```

To run and test:

```sh
echo '{1,{2,3},4}' | ./antlr4_study
```
