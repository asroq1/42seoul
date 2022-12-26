/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:18 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/26 14:38:05 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

    Intern someRandomIntern;
    AForm *shrubbery;
    // AForm *presidential;
    // AForm *robotot;
    // AForm *wrongForm;

    std::cout << std::endl;

    try {
        shrubbery = someRandomIntern.makeForm("shrubbery request", "Bender");
        std::cout << shrubbery->getName() << std::endl;
        std::cout << std::endl;

        // robotot = someRandomIntern.makeForm("robotomy request", "hyunjung");
        // std::cout << robotot->getName() << std::endl;
        // std::cout << std::endl;

        // presidential =
        //     someRandomIntern.makeForm("presidential request", "avatar");
        // std::cout << presidential->getName() << std::endl;
        // std::cout << std::endl;

        // wrongForm = someRandomIntern.makeForm("wrong request", "mistake");
        // std::cout << wrongForm->getName() << std::endl;
        // std::cout << std::endl;
    } catch (const std::exception &e) {

        std::cerr << e.what() << '\n';
    }

    return (0);
}
