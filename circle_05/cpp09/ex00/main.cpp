
#include <fstream>
#include <iostream>
#include <sstream>

#include "BitcoinExchange.hpp"
int main(int argc, const char** argv) {
    BitcoinExchange coinMap;

    if (argc == 1) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    ifstream infile("./data.csv");
    if (!infile.is_open()) {
        std::cerr << "Failed to open csv file" << std::endl;
        return 1;
    }
    coinMap.setPriceList(infile);
    for (int i = 1; i < argc; i++) {
        coinMap.setPurchaseList(argv[i]);
    }
    return 0;
}