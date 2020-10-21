//
// Created by Andrew Kireev on 21.10.2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>

void generate_matrix(std::ostream& out, int size) {
    std::random_device rd;
    std::mt19937 mersenne(rd());
    out << size << std::endl;
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            out <<  static_cast<int>(mersenne()) % 100 << " ";
        }
        out << std::endl;
    }
}


int main(int argc, char **argv) {

    std::ofstream file(argv[1]);

    int size;

    std::stringstream(argv[2]) >> size;
    generate_matrix(file, size);
    return 0;
}