#!/usr/bin/env bash

g++ -std=c++11 generate_matrix.cpp -o generator
./generator size_10 10
./generator size_23 23
./generator size_123 123
./generator size_200 10
./generator size_555 555
./generator size_666 666
./generator size_1333 1333
./generator size_1777 1777
./generator size_10000 10000