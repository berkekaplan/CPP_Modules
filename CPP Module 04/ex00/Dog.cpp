#include"Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog: Constructor called.\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog: Copy Constructor called.\n";
	*this = copy;
}

Dog::~Dog(){
	std::cout << "Dog : Destructor called.\n";
}

Dog& Dog ::operator =(const Dog& copy)
{
	Animal::type = copy.type;
	return(*this);
}

void Dog::makeSound ()const
{
	 std::cout << "Hav Hav" << std::endl;
}
