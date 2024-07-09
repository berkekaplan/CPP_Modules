#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n\033[0;31m-------------------------\033[m"<< std::endl;
    {
        Bureaucrat b("Donkey");
        try {
            Form a("Invalid Form", 1, 200);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;31m-------------------------\033[m"<< std::endl;
    {
        try {
        Bureaucrat a("Mary Jane", 20);
        Form f("Document Form", 20, 10);
        Form l(f);

        std::cout << f;
        a.signForm(f);
        std::cout << f;
        std::cout << l;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;31m-------------------------\033[m"<< std::endl;
    {
        try {
        Bureaucrat b("Peter Parker", 50);
        Form f("Application Form", 40, 20);
        
        std::cout << f;
        
        b.signForm(f);
        
        std::cout << f;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;31m-------------------------\033[m"<< std::endl;
    std::cout << "\n" << std::endl;
}
