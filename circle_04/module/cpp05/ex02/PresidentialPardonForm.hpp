/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:40:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/12/23 13:52:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
  private:
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &ref);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
    void execute(const Bureaucrat &executor) const;
};

#endif
