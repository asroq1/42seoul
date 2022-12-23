/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:45:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 13:52:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
  private:
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &ref);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
    void execute(const Bureaucrat &executor) const;
};

#endif
