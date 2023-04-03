
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setText(std::string argv) {
    std::string data;
    std::string price;

    std::ifstream textFile(argv);
    if (!textFile.is_open()) {
        std::cerr << "Failed to open" << std::endl;
        return;
    }

    while (std::getline(textFile, data)) {
        std::getline(textFile, data, '|');
        std::getline(textFile, price);
        this->_text[data] = atof(price.c_str());
    }
}
std::map<std::string, float> BitcoinExchange::getText() { this->_text; }

void BitcoinExchange::setPrice(std::string data, float price) {
    this->_data[data] = price;
}

std::map<std::string, float> BitcoinExchange::getPrice() { this->_data; }

void BitcoinExchange::printPrice() {
    if (_data.begin()->first == _text.begin()->first) {
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
    std::cout << "_data.begin()->first" << _data.begin()->first << std::endl;
    std::cout << "_text.begin()->first" << _text.begin()->first << std::endl;
}
