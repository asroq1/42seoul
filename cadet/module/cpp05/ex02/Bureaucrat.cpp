/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:23 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/22 18:02:01 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){};

Bureaucrat::Bureaucrat(int grade, std::string name)
    : _name(name), _grade(grade) {

    if (_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (_grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref) { this->_grade = ref.getGrade(); }
Bureaucrat::~Bureaucrat(){};

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Too high grade !";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Too Low grade !";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref) {
    if (this != &ref) {
        this->_grade = ref.getGrade();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << " bureaucrat grade is " << obj.getGrade();
    return os;
}

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }
void Bureaucrat::increaseGrade(int grade) {
    this->_grade -= grade;
    if (this->getGrade() < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decreaseGrade(int grade) {
    this->_grade += grade;
    if (this->getGrade() > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName()
                  << std::endl;
    } catch (const std::exception &e) {
        std::cerr << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName()
                  << std::endl;
    } catch (const std::exception &e) {
        std::cerr << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
