

#include "RPN.hpp"

int main(int argc, const char** argv) {
    if (argc == 1) {
        return 1;
    }
    RPN polish;
    std::string tmp = argv[1];
    // " 1 ", " 2 " 예외처리를 위해 문자열 파싱 이후 0 ~ 10 체크
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
    int num = atoi(tmp.c_str());
    if ((tmp[0] == 0 || tmp[1] == 0) && num >= 0 && num <= 10) {
        std::cout << "Error : wrong expression" << std::endl;
        return 1;
    }

    polish.parseArgv(argv[1]);

    while (!polish._myStacks.empty() && !polish._flag) {
        std::cout << polish._myStacks.top() << std::endl;
        polish._myStacks.pop();
    }
    return 0;
}