/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/22 18:02:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    Bureaucrat citizen(150, "citizen");
    Bureaucrat president(1, "president");
    ShrubberyCreationForm form("strawberry");

    std::cout << citizen << std::endl;
    std::cout << president << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    citizen.executeForm(form);
    std::cout << citizen << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    president.executeForm(form);
    std::cout << president << std::endl;
    std::cout << form << std::endl;
    std::cout << std::endl;

    return (0);
}
