#include "PhoneBook.hpp"

void	printWelcome()
{
    std::cout << "\n" << "Welcome to the PhoneBook" << std::endl;
    std::cout << "Use SEARCH to browse your contacts, ADD to add one, and EXIT to... exit" << std::endl;
	std::cout << "waiting for command..." << "\n" << std::endl;
}

int main(void)
{
    std::string command;
    PhoneBook pb;

    printWelcome();
    while (true)
    {   
        std::getline(std::cin, command);
        if (command.compare("ADD") == 0)
            pb.addContact();
        else if (command.compare("SEARCH") == 0)
            pb.searchContact();
        else if (command.compare("EXIT") == 0)
        {
            std::cout << "Goodbye!" << std::endl;
            break ;
        }
        else
            std::cout << "This command doesn't exist." << std::endl;
    }
    return (0);
}
