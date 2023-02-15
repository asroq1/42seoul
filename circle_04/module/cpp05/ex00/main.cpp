/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/26 12:50:16 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat cadet(200, "hyunjung");
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    try {
        Bureaucrat a(150, "a");
        Bureaucrat b(1, "b");

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << std::endl;

        a.increaseGrade(5);
        b.decreaseGrade(5);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << std::endl;

        a.decreaseGrade(6);
        b.increaseGrade(7);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
