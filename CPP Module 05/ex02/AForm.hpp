#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const unsigned int _requiredGradeToSign;
        const unsigned int _requiredGradeToExecute;
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(std::string name);
        AForm(std::string name,
            int requiredGradeToSign,
            int requiredGradeToExecute);
        AForm(const AForm& copy);
        AForm &operator=(const AForm& copy);
        std::string getName(void) const;
        unsigned int getGradeToSign(void) const;
        unsigned int getGradeToExec(void) const;
        std::string getIsSigned(void) const;
        void beSigned(Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
        virtual void specificExecute(void) const = 0;
        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
        class FormNotSignedException: public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, AForm& f);