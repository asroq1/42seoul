/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:56 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/04 16:45:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <vector>

int main() {
    int iArr[5] = {1, 2, 3, 4, 5};
    double dArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char cArr[5] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Print Integer Arr" << std::endl;
    iter(iArr, 5, print);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Print Double Arr" << std::endl;
    iter(dArr, 5, print);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Print Character Arr" << std::endl;
    iter(cArr, 5, print);

    std::cout << "Calc test" << std::endl;
    int testArr[2] = {1, 2};
    std::cout << "cal Integer Arr" << std::endl;
    iter(testArr, 2, increaotr);
    std::cout << testArr[0] << std::endl;
    std::cout << testArr[1] << std::endl;

    std::cout << std::endl;

    return 0;
}
