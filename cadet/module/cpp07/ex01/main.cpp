/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:57:56 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/03 18:10:13 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

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

    return 0;
}
