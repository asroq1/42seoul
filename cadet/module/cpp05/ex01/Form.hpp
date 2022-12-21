#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

// 순환참조 때문에 이렇게 선언한다.
class Bureaucrat;
class Form {
  private:
    const std::string _name;
    const int _signGrade;
    const int _executeGrade;
    bool _isSigned;

  public:
    // Form();
    Form(std::string name, int signGrade, int executeGrade);
    Form(const Form &ref);
    ~Form();

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    Form &operator=(const Form &ref);
    void beSigned(const Bureaucrat &obj);
    const std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getSigned() const;
};
std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
