#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal : Constructor called.\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal : Constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal : Copy Constructor called.\n";
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal ::operator =(const WrongAnimal& copy)
{
	this->type = copy.type;
	return(*this);
}

void WrongAnimal::makeSound ()const
{
	 std::cout << "regular WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}
