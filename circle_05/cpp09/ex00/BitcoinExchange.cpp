
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) { *this = ref; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
    _purchaseList = ref._purchaseList;
    _priceList = ref._priceList;
    return *this;
}

void BitcoinExchange::setPurchaseList(std::string argv) {
    std::string line;
    std::string str;
    float price;

    std::map<std::string, float>::iterator it;
    std::ifstream purchaseList(argv);

    if (!purchaseList.is_open()) {
        std::cerr << "Failed to open input" << std::endl;
        return;
    }
    std::getline(purchaseList, line);
    // 위에서 date | value는 스킵해버리고 밑에서 stringstream으로 따로 저장
    while (std::getline(purchaseList, line)) {
        std::stringstream ss(line);
        std::string date, quantity;
        std::getline(ss, date, '|');
        std::getline(ss, quantity, '\n');
        // 공백 들어오면 멈추기 위해 사용
        if (line.empty()) {
            break;
        }
        it = _priceList.lower_bound(date);
        // 해당 date를 못찾으면 --it를 통해 이전 값을 출력
        if (date != it->first) {
            --it;
        }

        price = atof(quantity.c_str());

        if (it == _priceList.end()) {
            std::cout << "Can't find date" << std::endl;
            return;
        }

        if (checkQuantity(quantity) || checkDate(date)) {
        } else {
            std::cout << date << " "
                      << "=>" << quantity << " = " << (price * it->second)
                      << std::endl;
        }
    }
    purchaseList.close();
}
std::map<std::string, float> BitcoinExchange::getText() const {
    return this->_purchaseList;
}

// Price
void BitcoinExchange::setPriceList(std::ifstream& infile) {
    std::string date;
    std::string price;
    float f;

    while (std::getline(infile, date, ',')) {
        if (!std::getline(infile, price)) {
            break;  // 빈 문자열이 반환되면 반복문 종료
        }
        std::stringstream ss(price);
        if (ss >> f) {
            this->_priceList[date] = f;
        }
    }
    infile.close();
}

std::map<std::string, float> BitcoinExchange::getPrice() const {
    return this->_priceList;
}

bool BitcoinExchange::checkQuantity(std::string quantity) {
    if (quantity[1] == '-') {
        std::cout << "Error: not a positive number." << std::endl;
        return true;
    } else if (atof(quantity.c_str()) > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return true;
    }
    return false;
}

bool BitcoinExchange::checkDate(std::string date) {
    std::string year;
    std::string month;
    std::string day;
    unsigned int dayMax;
    std::stringstream ss(date);

    // 정상적인 포맷이 아니면 에러
    if (date.size() != 11) {
        std::cout << "Error: bad input => " << date << std::endl;
        return true;
    }
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');

    unsigned n_year = std::atoi(year.c_str());
    unsigned n_month = std::atoi(month.c_str());
    unsigned n_day = std::atoi(day.c_str());
    dayMax = 31;
    if (n_month == 4 || n_month == 6 || n_month == 9 || n_month == 11) {
        dayMax = 30;
    } else if (n_month == 2) {
        dayMax = 28;
        // 위 조건은 윤년
        if ((n_year % 4 == 0 && n_year % 100 != 0) || n_year % 400 == 0) {
            dayMax = 29;
        }
    }

    if (((n_year < 2009 || n_year > 2022) || (n_month > 12) || (n_month < 1) ||
         (n_month > 12) || (n_day < 1 || n_day > dayMax))) {
        std::cout << "Error: bad input => " << n_year << "-" << n_month << "-"
                  << n_day << std::endl;
        return true;
    }
    return false;
}