
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setText(std::string argv) {
    std::string line;
    std::string str;
    float price;

    // float value;

    std::map<std::string, float>::iterator it;
    std::ifstream textFile(argv);

    if (!textFile.is_open()) {
        std::cerr << "Failed to open" << std::endl;
        return;
    }

    std::getline(textFile, line);
    while (std::getline(textFile, line)) {
        // std::cout << "line :" << line << std::endl;
        std::stringstream ss(line);
        std::string date, quantity;
        std::getline(ss, date, ',');
        std::getline(ss, quantity, ',');
        // std::cout << "Date is: " << date << std::endl;

        it = _data.lower_bound(date);
        --it;
        price = atof(quantity.c_str());

        // std::cout << "what is it: " << it->first << std::endl;
        if (it == _data.end()) {
            std::cout << "Can't find date" << std::endl;
            return;
        }
        std::cout << date << " "
                  << "=>" << quantity << " = " << (price * it->second)
                  << std::endl;
    }

    // for (itt = _text.begin(); itt != _text.end(); itt++) {
    //     std::cout << "Date : " << itt->first << " Quantity : " <<
    //     itt->second
    //               << std::endl;
    // }
    // textFile.close();
}
std::map<std::string, float> BitcoinExchange::getText() { return this->_text; }

// Price
void BitcoinExchange::setPrice() {
    std::string data;
    std::string price;
    float f;
    std::ifstream infile("./data.csv");
    if (!infile.is_open()) {
        std::cerr << "Failed to open" << std::endl;
        return;
    }
    while (std::getline(infile, data, ',')) {
        if (!std::getline(infile, price)) {
            break;  // 빈 문자열이 반환되면 반복문 종료
        }
        std::stringstream ss(price);
        if (ss >> f) {
            this->_data[data] = f;
        } else {
            std::cerr << "Conversion error" << std::endl;
        }
    }
    // for (auto it = this->_data.begin(); it != this->_data.end(); it++) {
    //     std::cout << "Date: " << it->first << " Price: " << it->second
    //               << std::endl;
    // }

    infile.close();
}

std::map<std::string, float> BitcoinExchange::getPrice() { return this->_data; }

void BitcoinExchange::printPrice() {
    std::map<std::string, float>::iterator it;
    std::map<std::string, float>::iterator itt;

    // for (auto it = this->_data.begin(); it != this->_data.end(); it++) {
    //     std::cout << "key : " << it->first << " : " << it->second <<
    //     std::endl;
    // }

    // for (it = _data.begin(); it != _data.end(); ++it) {
    //     std::cout << "data : " << it->first << std::endl;

    // for (itt = _text.begin(); itt != _text.end(); itt++) {
    //     std::cout << "_fir : " << itt->first << "!_sec : " << itt->second
    //               << std::endl;

    // if (it->first == itt->first) {
    //     std::cout << "we got it" << std::endl;
    // }
}
//}

std::map<std::string, float>::iterator key;

// lower_bound 사용
// for (it = _text.begin(); it != _text.end(); it++) {
//    std::cout << it->first << std::endl;
//    key = _data.lower_bound(_text.begin()->first);
//    if (key == _data.end()) {
//        std::cout << "No key found" << std::endl;
//    } else {
//        std::cout << "Found key: " << key->first << std::endl;
//    }
//}

// std::map<std::string, float>::iterator it, tit;
// it = this->_data.begin();
// tit = this->_text.begin();
// std::cout << "data : " << it->first << " text : " << tit->first
//           << std::endl;
//  std::cout << "what is :" << _data.begin()->first << std::endl;
