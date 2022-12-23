/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:18:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 14:21:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {
  private:
    AForm *formArr[3];

  public:
    Intern();
    Intern(const Intern &ref);
    ~Intern();

    class bigMistakeExecption : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    Intern &operator=(const Intern &ref);
    AForm *makeForm(std::string form, std::string target);
};

#endif
