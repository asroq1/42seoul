/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:29:21 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/18 14:33:10 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat();
    Bureaucrat(int grade, const std::string name);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();
    class GradeTooHighException : public std::exception {
      public:
        //앞 const는 return값만 const라는 의미.
        //뒤 const는 const객체만 사용이 가능하다
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        //앞 const는 return값만 const라는 의미.
        //뒤 const는 const객체만 사용이 가능하다
        virtual const char *what() const throw();
    };

    Bureaucrat &operator=(const Bureaucrat &ref);
    Bureaucrat &operator<<(const Bureaucrat &ref);

    std::string getName() const;
    int getGrade() const;
    void increaseGrade(int grade);
    void decreaseGrade(int grade);
};

#endif
