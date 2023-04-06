#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& ref) { _myStacks = ref._myStacks; }

RPN::~RPN() {}

void RPN::parseArgv(std::string argv) {
    _ss << argv;
    std::string token;
    std::stack<int> tempStack;

    while (_ss >> token) {
        for (int i = 0; i < token.length(); i++) {
            if (isdigit(token[i])) {
                _myStacks.push(token[i] - '0');
            } else if (token[i] == '+' || token[i] == '-' || token[i] == '/' ||
                       token[i] == '*') {
                if (!_myStacks.empty() || _myStacks.size() >= 2) {
                    int result;
                    int operand1 = _myStacks.top();
                    _myStacks.pop();
                    int operand2 = _myStacks.top();
                    _myStacks.pop();
                    if (token[i] == '+') {
                        result = operand2 + operand1;
                    } else if (token[i] == '-') {
                        result = operand2 - operand1;
                    } else if (token[i] == '/') {
                        result = operand2 / operand1;
                    } else if (token[i] == '*') {
                        result = operand2 * operand1;
                    }
                    _myStacks.push(result);
                }
            }
        }
    }
}

// void RPN::setArgv(std::string argv) { _myStacks.push(argv); }

std::stack<int> RPN::getArgv() { return this->_myStacks; }
