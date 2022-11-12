# CSI2372 Assignment 2

## Student Info
* Name: Hongyi Lin
* Student Number: 300053082

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
    ./TestGraph
    ```

The default binary name is `TestGraph`. You can change it in `CMakeLists.txt` if you want.
