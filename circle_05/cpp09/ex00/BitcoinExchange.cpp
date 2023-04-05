
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
    this->_data = ref.getPrice();
    this->_text = ref.getText();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::setText(std::string argv) {
    std::string line;
    std::string str;
    float price;

    std::map<std::string, float>::iterator it;
    std::ifstream textFile(argv);

    if (!textFile.is_open()) {
        std::cerr << "Failed to open input" << std::endl;
        return;
    }
    std::getline(textFile, line);
    while (std::getline(textFile, line)) {
        std::stringstream ss(line);
        std::string date, quantity;
        std::getline(ss, date, '|');
        std::getline(ss, quantity, '\n');
        if (line.empty()) {
            break;
        }

        it = _data.lower_bound(date);
        if (date != it->first) {
            --it;
        }

        price = atof(quantity.c_str());

        if (it == _data.end()) {
            std::cout << "Can't find date" << std::endl;
            return;
        }

        if (checkQuantity(quantity)) {
        } else if (checkdate(date)) {
        } else {
            std::cout << date << " "
                      << "=>" << quantity << " = " << (price * it->second)
                      << std::endl;
        }
    }
    textFile.close();
}
std::map<std::string, float> BitcoinExchange::getText() const {
    return this->_text;
}

// Price
void BitcoinExchange::setPrice() {
    std::string data;
    std::string price;
    float f;
    std::ifstream infile("./data.csv");
    if (!infile.is_open()) {
        std::cerr << "Failed to open csv files" << std::endl;
        return;
    }
    while (std::getline(infile, data, ',')) {
        if (!std::getline(infile, price)) {
            break;  // 빈 문자열이 반환되면 반복문 종료
        }
        std::stringstream ss(price);
        if (ss >> f) {
            this->_data[data] = f;
        }
    }
    infile.close();
}

std::map<std::string, float> BitcoinExchange::getPrice() const {
    return this->_data;
}

bool BitcoinExchange::checkQuantity(std::string quantity) {
    // if (quantity.size() == 0 && date.size()) {
    //     std::cout << "Error: don't have any quantity." << std::endl;
    // }
    if (quantity[1] == '-') {
        std::cout << "Error: not a positive number." << std::endl;
        return true;
    } else if (atof(quantity.c_str()) > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return true;
    }
    return false;
}

bool BitcoinExchange::checkdate(std::string date) {
    std::string year;
    std::string month;
    std::string day;
    unsigned int dayMax;
    std::stringstream ss(date);

    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');

    unsigned n_year = std::atoi(year.c_str());
    unsigned n_month = std::atoi(month.c_str());
    unsigned n_day = std::atoi(day.c_str());
    if ((n_year % 4 == 0 && n_year % 100 != 0) || n_year % 400 == 0) {
        if (n_month == 2) {
            dayMax = 29;
        } else {
            dayMax = 31;
        }
        return false;
    } else {
        dayMax = 30;
    }
    if (n_month < 1 || n_month > 12) {
        std::cout << "Error: bad input => " << n_year << "-" << n_month << "-"
                  << n_day << std::endl;
        return true;
    }
    if (n_day < 1 || n_day > dayMax) {
        std::cout << "Error: bad input => " << n_year << "-" << n_month << "-"
                  << n_day << std::endl;
        return true;
    }
    return false;
}
