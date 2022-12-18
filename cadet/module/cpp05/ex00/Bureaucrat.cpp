/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:23 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/18 14:35:28 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){};

Bureaucrat::Bureaucrat(int grade, const std::string name)
    : _grade(grade), _name(name) {
    //위랑
    // this->grade = grade;의 차이점은 무엇인지 ?
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

Bureaucrat &Bureaucrat::operator<<(const Bureaucrat &ref) {
    std::cout << ref.getName() << "bureaucrat grade is" << ref.getGrade()
              << std::endl;
    return this;
}

std::string Bureaucrat::getName() const {
    std::cout << "name :" << this->_name << std::endl;
    return this->_name;
}
int Bureaucrat::getGrade() const {
    std::cout << "grade :" << this->_grade << std::endl;
    return this->_grade;
}
void Bureaucrat::increaseGrade(int grade) { this->_grade -= grade; }
void Bureaucrat::decreaseGrade(int grade) { this->_grade += grade; }