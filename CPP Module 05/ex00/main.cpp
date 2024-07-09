#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[0;31m-------------------------"<< std::endl;
    std::cout << "Decrease Grade\033[m\n"<< std::endl;

    Bureaucrat b("John");
    std::cout << b << std::endl;
    try {
        b.decreaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    
    std::cout << "\033[0;34m-------------------------"<< std::endl;

    std::cout << "Increase Grade\033[m\n"<< std::endl;

    try {
    Bureaucrat a("Taylor", 5); 
        for (size_t i = 0; i < 5; ++i) {
            std::cout << a << std::endl;
            a.increaseGrade();
        }
        std::cout << a << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
