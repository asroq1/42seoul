#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& ref) { *this = ref; }

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& ref) {
    _myStacks = ref._myStacks;
    _ss << ref._ss.str();
    _flag = ref._flag;
    return *this;
}

void RPN::parseArgv(std::string argv) {
    _ss << argv;
    std::string token;

    while (_ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            int digit;
            std::istringstream(token) >> digit;

            if ((digit < 0 || digit > 10)) {
                std::cout << "This is bigger or smaller than 0 ~ 10 "
                          << std::endl;
                exit(1);
            }

            _myStacks.push(digit);
        } else if (token == "+" || token == "-" || token == "/" ||
                   token == "*") {
            if (_myStacks.size() >= 2) {
                int result = 0;
                int operand1 = _myStacks.top();
                _myStacks.pop();
                int operand2 = _myStacks.top();
                _myStacks.pop();
                if (token == "+") {
                    result = operand2 + operand1;
                } else if (token == "-") {
                    result = operand2 - operand1;
                } else if (token == "/") {
                    if (operand1 == 0) {
                        std::cout << "Error : floating point exception "
                                  << std::endl;
                        exit(1);
                    }
                    result = operand2 / operand1;
                } else if (token == "*") {
                    result = operand2 * operand1;
                }

                if ((result > 2147483647) || (result < -2147483648)) {
                    std::cout << "Error: result overflow" << std::endl;
                    exit(1);
                }
                _myStacks.push(result);
            } else {  //  ./RPN "/ +" 처럼 empty가 아닌 경우 방지
                std::cout << "Error : Wrong Expressions" << std::endl;
                _flag = true;
                exit(1);
            }
        } else {
            std::cout << "Error : not valid token" << std::endl;
            _flag = true;
            exit(1);
        }
    }
    if (_myStacks.size() != 1) {
        std::cout << "Error : wrong expression" << std::endl;
        _flag = true;
        exit(1);
    }
}

std::stack<int> RPN::getArgv() { return this->_myStacks; }
