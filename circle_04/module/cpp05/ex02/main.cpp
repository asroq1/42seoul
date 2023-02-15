/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 13:59:14 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    Bureaucrat citizen(150, "citizen");
    Bureaucrat president(1, "president");
    ShrubberyCreationForm form("strawberry");

    std::cout << "------------ShrubberyCreationForm-----------" << std::endl;
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

    std::cout
        << "---------------------RobotomyRequestForm------------------------"
        << std::endl;
    RobotomyRequestForm robotForm("robot");
    std::cout << citizen << std::endl;
    std::cout << president << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << std::endl;

    citizen.executeForm(form);
    std::cout << citizen << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << std::endl;

    president.executeForm(robotForm);
    std::cout << president << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------"
              << std::endl;

    std::cout
        << "---------------------PresidentialPardonForm------------------------"
        << std::endl;
    PresidentialPardonForm preForm("pre");
    std::cout << citizen << std::endl;
    std::cout << president << std::endl;
    std::cout << robotForm << std::endl;
    std::cout << std::endl;

    citizen.executeForm(preForm);
    std::cout << citizen << std::endl;
    std::cout << preForm << std::endl;
    std::cout << std::endl;

    president.executeForm(preForm);
    std::cout << president << std::endl;
    std::cout << preForm << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------"
              << std::endl;
    return (0);
}
