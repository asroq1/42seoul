
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
    std::string data;
    std::string price;
    BitcoinExchange coinMap;

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
    }

    // std::ifstream infile(argv[1]);\


    coinMap.setText(argv[1]);
    std::ifstream infile("./data.csv");
    if (!infile.is_open()) {
        std::cerr << "Failed to open" << std::endl;
        return 1;
    }

    while (std::getline(infile, data)) {
        std::getline(infile, data, ',');
        // std::cout << "data :" << data << std ::endl;
        std::getline(infile, price);
        // std::cout << "price : " << price << std ::endl;
        coinMap.setPrice(data, atof(price.c_str()));
    }
    // for (auto it = coinMap._data.begin(); it != coinMap._data.end(); it++) {
    //     std::cout << it->first << " : " << it->second << std::endl;
    // }

    // for (auto it = coinMap._text.begin(); it != coinMap._data.end(); it++) {
    //     std::cout << it->first << " : " << it->second << std::endl;
    // }

    coinMap.printPrice();
    infile.close();
    return 0;
}