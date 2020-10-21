#!/usr/bin/env bash

g++ generate_matrix.cpp -o generator
./generator size_10 10
./generator size_23 23