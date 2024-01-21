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
        std::getline(std::cin, command); // get the command from the user
        if (command.compare("ADD") == 0) // compare the command with the string "ADD"
            pb.addContact(); // if it's the same, call the addContact function
        else if (command.compare("SEARCH") == 0) // compare the command with the string "SEARCH"
            pb.searchContact(); // if it's the same, call the searchContact function
        else if (command.compare("EXIT") == 0) // compare the command with the string "EXIT"
        {
            std::cout << "Goodbye!" << std::endl; // if it's the same, print "Goodbye!" and exit the program
            break ;
        }
        else
            std::cout << "This command dosen't exist." << std::endl; // if it's not the same, print "This command dosen't exist."
    }
    return (0);
}
