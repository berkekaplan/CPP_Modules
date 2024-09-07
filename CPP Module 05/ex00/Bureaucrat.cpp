#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()) {
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

void Bureaucrat::increaseGrade(void) {
    setGrade(getGrade() - 1);
}

void Bureaucrat::decreaseGrade(void) {
    setGrade(getGrade() + 1);
}

void Bureaucrat::setGrade(int n) {
    if (n < 1)
        throw GradeTooHighException();
    else if (n > 150)
        throw GradeTooLowException();
    _grade = n;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}
