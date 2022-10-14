# CSI2372 Assignment 1

## Student Info
* Name: Hongyi Lin
* Student Number: 300053082

## Compile and Run

* Recommend Linux system.
* Recommend [cmake](https://cmake.org).


1. Put the professor's test file in the same directory with my source code.
2. Compile my code with following commands
    ```bash
    mkdir build
    cmake -S . -B ./build
    cd build
    make
    # run the test
    ./TestBigInteger
    ```

The default binary name is `TestBigInteger`. You can change it in `CMakeLists.txt` if you want.
