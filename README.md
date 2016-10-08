# KnightSequences

This is C++ implementation of popular Knight Sequences problem. Current solution consists of 3 algorithms: brute-force recursive, recursive with memoization and bottom-up DP. It is using C++11 and has been tested on macOS Sierra.

Solution is using CMake build system. To build on system of your choice run

    cmake .
    
in the root directory of the project. This will create build files for default build system on your OS (Unix make on unix platforms). Alternatively you can specify one of non-default generators (eg Xcode) by running

    cmake . -G Xcode
    
To run project find `pathfinder.app` executable and run it with following command-line parameters

    ./pathfinder.app MODE SEQUENCE-LENGTH NUM-VOWELS-ALLOWED
