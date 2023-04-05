
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
    BitcoinExchange coinMap;

    if (argc == 1) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    coinMap.setPrice();
    for (int i = 1; i < argc; i++) {
        coinMap.setText(argv[i]);
    }
    return 0;
}