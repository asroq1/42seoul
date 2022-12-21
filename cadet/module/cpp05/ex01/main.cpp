/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/21 17:50:46 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat citizen(150, "a");
    Bureaucrat president(1, "b");
    Form c("c", 50, 50);

    std::cout << citizen << std::endl;
    std::cout << president << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl;

    citizen.signForm(c);
    std::cout << citizen << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl;

    president.signForm(c);
    std::cout << president << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl;

    return (0);
}
