/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Internn.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:18:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 14:22:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    formArr[0] = new ShrubberyCreationForm();
    formArr[1] = new RobotomyRequestForm();
    formArr[2] = new PresidentialPardonForm();
    std::cout << "111" << std::endl;
};

Intern::Intern(const Intern &ref) { *this = ref; };

Intern::~Intern() {
    delete formArr[0];
    delete formArr[1];
    delete formArr[2];
};

Intern &Intern::operator=(const Intern &ref) {
    (void)ref;
    return *this;
};

const char *Intern::bigMistakeExecption::what() const throw() {
    return "You just got a big mistake";
};

AForm *Intern::makeForm(std::string form, std::string target) {
    std::string formBox[3] = {"shrubbery request", "robotomy request",
                              "presidential request"};
    std::cout << "222" << std::endl;

    for (int i = 0; i < 3; i++) {
        if (form == formBox[i]) {
            return this->formArr[i]->copy(target);
        }
    }
    throw Intern::bigMistakeExecption();
    return 0;
};