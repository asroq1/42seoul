#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& ref) { _myStacks = ref._myStacks; }

RPN::~RPN() {}

void RPN::parseArgv(std::string argv) {
    _ss << argv;
    std::string token;
    std::stack<int> tempStack;

    while (_ss >> token) {
        int digit;
        if (isdigit(token[0]) || token[0] == '-' && isdigit(token[1])) {
            std::istringstream(token) >> digit;
            if (digit < 0 || digit > 10) {
                std::cout << "This is bigger or smaller than between 0 ~ 10 "
                          << std::endl;
                break;
            }
            _myStacks.push(digit);
        } else if (token == "+" || token == "-" || token == "/" ||
                   token == "*") {
            if (!_myStacks.empty() || _myStacks.size() >= 2) {
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
                    result = operand2 / operand1;
                } else if (token == "*") {
                    result = operand2 * operand1;
                }
                _myStacks.push(result);
            }
        } else {
            std::cout << "Error" << std::endl;
            _flag = true;
            return;
        }
    }
}

// void RPN::setArgv(std::string argv) { _myStacks.push(argv); }

std::stack<int> RPN::getArgv() { return this->_myStacks; }
