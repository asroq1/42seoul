/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:49:50 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/04 16:57:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// void leaker() { system("leaks a.out"); }

int main() {

    // atexit(leaker);
    try {
        Array<int> iArr(5);
        std::cout << "iArr size : " << iArr.size() << std ::endl;
        for (int i = 0; i < 5; i++)
            iArr[i] = i + 1;
        for (int i = 0; i < 5; i++)
            std::cout << iArr[i] << std::endl;
        try {
            std::cout << iArr[5] << std::endl;
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
        }

        std::cout << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << std::endl;

        Array<int> copiedArray(iArr);
        for (int i = 0; i < 5; i++)
            std::cout << "iArr[" << i << "] = " << iArr[i] << " iArray2[" << i
                      << "]= " << copiedArray[i] << std::endl;

        std::cout << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << std::endl;

        std::cout << "iArr's address : " << &iArr << std::endl;
        std::cout << "copiedArray's address : " << &copiedArray << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}
