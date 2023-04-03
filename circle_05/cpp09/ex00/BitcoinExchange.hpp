#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange {
   private:
   public:
    std::map<std::string, float> _text;
    std::map<std::string, float> _data;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ref);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& ref);
    void setText(std::string argv);
    void setPrice(std::string data, float price);
    std::map<std::string, float> getPrice();
    std::map<std::string, float> getText();

    void printPrice();
};

#endif
