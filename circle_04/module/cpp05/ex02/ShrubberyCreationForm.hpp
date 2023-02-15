#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
  private:
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &ref);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
    void execute(const Bureaucrat &executor) const;
};

#endif
