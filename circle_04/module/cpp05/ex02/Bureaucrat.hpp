/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/22 17:37:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;
class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat();
    Bureaucrat(int grade, std::string name);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception {
      public:
        // 앞 const는 return값만 const라는 의미.
        // 뒤 const는 const객체만 사용이 가능하다
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        // 앞 const는 return값만 const라는 의미.
        // 뒤 const는 const객체만 사용이 가능하다
        virtual const char *what() const throw();
    };

    Bureaucrat &operator=(const Bureaucrat &ref);
    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int grade);
    void decreaseGrade(int grade);
    void signForm(AForm &form) const;
    void executeForm(const AForm &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
#endif
