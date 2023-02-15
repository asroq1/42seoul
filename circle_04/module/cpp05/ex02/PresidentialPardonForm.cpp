/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 13:59:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &ref) {
    *this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

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
