/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:51:04 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/21 17:54:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form::Form(){};

Form::Form(std::string name, int signGrade, int executeGrade)
    : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || executeGrade > 150) {
        throw Form::GradeTooLowException();
    }
};

Form::Form(const Form &ref)
    : _name(ref._name), _signGrade(ref._signGrade),
      _executeGrade(ref._executeGrade) {
    *this = ref;
};
Form::~Form() {}

Form &Form::operator=(const Form &ref) {
    if (this != &ref) {
        this->_isSigned = ref._isSigned;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() <= this->_signGrade) {
        this->_isSigned = true;
    } else if (obj.getGrade() > this->_signGrade) {
        throw Form::GradeTooLowException();
    }
}
int Form::getSignGrade() const { return this->_signGrade; }
int Form::getExecuteGrade() const { return this->_executeGrade; }
bool Form::getSigned() const { return this->_isSigned; }
const std::string Form::getName() const { return this->_name; }

std::ostream &operator<<(std::ostream &os, const Form &obj) {
    os << obj.getName() << " signed : " << std::boolalpha << obj.getSigned()
       << " Sign Grade : " << obj.getSignGrade()
       << " Execute Grade : " << obj.getSignGrade();
    return os;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Too high grade !";
}
const char *Form::GradeTooLowException::what() const throw() {
    return "Too Low grade !";
}
