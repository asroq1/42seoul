
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
    BitcoinExchange coinMap;

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
    }

    coinMap.setPrice();
    coinMap.setText(argv[1]);

    coinMap.printPrice();
    return 0;
}