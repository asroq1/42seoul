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
    std::stack<int> tempStack;

    while (_ss >> token) {
        int digit;
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            std::istringstream(token) >> digit;
            if (digit < 0 || digit > 10) {
                std::cout << "This is bigger or smaller than between 0 ~ 10 "
                          << std::endl;
                break;
            }
            _myStacks.push(digit);
        } else if (token == "+" || token == "-" || token == "/" ||
                   token == "*") {
            if (_myStacks.size() >= 2) {
                int result;
                int operand1 = _myStacks.top();
                _myStacks.pop();
                int operand2 = _myStacks.top();
                _myStacks.pop();
                if (token == "+") {
                    result = operand2 + operand1;
                } else if (token == "-") {
                    result = operand2 - operand1;
                } else if (token == "/") {
                    if (operand1 == 0 || operand2 == 0) {
                        std::cout << "Error : floating point exception "
                                  << std::endl;
                        return;
                    }
                    result = operand2 / operand1;
                } else if (token == "*") {
                    result = operand2 * operand1;
                }
                _myStacks.push(result);
            } else {  //  ./RPN "/ +" 처럼 empty가 아닌 경우 방지
                std::cout << "Error" << std::endl;
                _flag = true;
                return;
            }
        } else {
            std::cout << "Error" << std::endl;
            _flag = true;
            return;
        }
    }
}

std::stack<int> RPN::getArgv() { return this->_myStacks; }
