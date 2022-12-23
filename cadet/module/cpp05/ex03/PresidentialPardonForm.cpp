/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 17:27:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential", 25, 5) {
    std::cout << "PresidentialPardonForm Construct called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5) {
    std::cout << "Target PresidentialPardonForm Construct called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &ref) {
    *this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destruct called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
    (void)ref;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (executor.getGrade() > 25) {
        throw AForm::NotEnoughSignExceeption();
    } else if (executor.getGrade() > 5) {
        throw AForm::NotEnoughExecuteExceeption();
    }
    std::cout << executor.getName()
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm *PresidentialPardonForm::copy(const std::string type) const {
    return new PresidentialPardonForm(type);
}