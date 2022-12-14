# Final Exam

- [Final Exam](#final-exam)
  - [Student](#student)
  - [Source Code](#source-code)
  - [Compilation](#compilation)

***

## Student
* **Name**: Hongyi Lin
* **Student No.**: 300053082

## Source Code
The source code for 3 questions are in the folder `q1`, `q2` and `q3` respectively.

## Compilation
Each folder contains a `CMakeLists.txt` which can be used to generate the build scripts.

* Compilation in Linux
    ```bash
    # use q1 as example
    cd q1
    mkdir build
    cmake -S . -B build
    cd build
    make
    ./TestQ1
    ```
