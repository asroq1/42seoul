#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
   public:
    std::stack<int> _myStacks;
    std::stringstream _ss;
    bool _flag;

    RPN();
    RPN(const RPN& ref);
    ~RPN();

    RPN& operator=(const RPN& ref);
    void setArgv(std::string argv);
    std::stack<int> getArgv();
    void parseArgv(std::string argv);
};

#endif
