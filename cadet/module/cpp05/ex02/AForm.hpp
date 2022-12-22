/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:35 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/22 17:51:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

// 순환참조 때문에 이렇게 선언한다.
class Bureaucrat;
class AForm {
  private:
    const std::string _name;
    const int _signGrade;
    const int _executeGrade;
    bool _isSigned;

  public:
    AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    AForm(const AForm &ref);
    ~AForm();

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class SCFHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class SCFLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class SCFExecException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class PPFHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class PPFLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class RRFHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class RRFLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    AForm &operator=(const AForm &ref);
    void beSigned(const Bureaucrat &obj);
    const std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getSigned() const;
    virtual void execute(const Bureaucrat &executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
