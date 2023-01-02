/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:27:28 by hyunjung          #+#    #+#             */
/*   Updated: 2023/01/02 17:57:08 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string.h>

int main(void) {
    whatever oasis;
    int a = 2;
    int b = 3;

    oasis.swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << oasis.min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << oasis.max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    oasis.swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << oasis.min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << oasis.max(c, d) << std::endl;
    return 0;
}