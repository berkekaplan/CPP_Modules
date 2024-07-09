#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm::AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm::AForm("RobotomyRequestForm", 72, 45) {
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this != &copy)
       _target = copy._target;
    return *this; 
}

void RobotomyRequestForm::specificExecute(void) const {
    std::srand(time(0));
    size_t t = std::rand();
    std::cout << "*DRILLING NOISES*" << std::endl;
    if (t % 2 == 0)
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy " <<_target << " failed!" << std::endl;       
}
