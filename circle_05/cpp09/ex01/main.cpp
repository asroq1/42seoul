

#include "RPN.hpp"

int main(int argc, const char** argv) {
    RPN polish;
    std::stack<int> tempStack;

    polish.parseArgv(argv[1]);

    while (!polish._myStacks.empty()) {
        tempStack.push(polish._myStacks.top());
        polish._myStacks.pop();
    }
    while (!tempStack.empty() && !polish._flag) {
        std::cout << tempStack.top() << std::endl;
        tempStack.pop();
    }

    return 0;
}