#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
class BitcoinExchange {
   private:
   public:
    std::map<std::string, float> _purchaseList;
    std::map<std::string, float> _priceList;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ref);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& ref);
    void setPurchaseList(std::string argv);
    void setPriceList(std::ifstream& infile);
    std::map<std::string, float> getPrice() const;
    std::map<std::string, float> getText() const;
    bool checkQuantity(std::string quantity);
    bool checkDate(std::string date);
};

#endif
