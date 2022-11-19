# CSI2372 Assignment 3

## Student Info
* Hongyi Lin, 300053082
* Stacy Guo, 300157080

## Compile and Run

* Recommend Linux system.
* Recommend [cmake](https://cmake.org).


1. Put the professor's testing code in the same directory with my source code.
2. Compile my code with following commands
    ```bash
    mkdir build
    cmake -S . -B ./build
    cd build
    make
    # run the test
    ./TestRelation_Template
    ./TestMappingRelation
    ```

The default binary names are `TestRelation_Template` and `TestMappingRelation`. You can change it in `CMakeLists.txt` if you want.
