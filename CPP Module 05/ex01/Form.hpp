#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredGradeToSign;
        const int _requiredGradeToExecute;
    public:
        Form(void);
        ~Form(void);
        Form(std::string name);
        Form(std::string name,
            int requiredGradeToSign,
            int requiredGradeToExecute);
        Form(const Form& copy);
        Form &operator=(const Form& copy);
        std::string getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExec(void) const;
        std::string getIsSigned(void) const;
        void beSigned(Bureaucrat& b);
        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, Form& f);