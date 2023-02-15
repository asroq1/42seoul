/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:45:13 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/26 14:40:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "RobotomyRequestForm Construct called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, 72, 45) {
    std::cout << "Target RobotomyRequestForm Construct called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) {
    *this = ref;
}
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destruct called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
    (void)ref;
    return *this;
}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > 145) {
        throw AForm::NotEnoughSignExceeption();
    } else if (executor.getGrade() > 137) {
        throw AForm::NotEnoughExecuteExceeption();
    }
    srand((unsigned int)time(NULL));
    int percent = rand() % 100;
    std::cout << "drill is working" << std::endl;
    if (percent < 50) {
        std::cout << "Drilling was Successfully done !";
    } else {
        std::cout << "Drilling was totally failed !";
    }
}

AForm *RobotomyRequestForm::copy(const std::string type) const {
    return new RobotomyRequestForm(type);
}