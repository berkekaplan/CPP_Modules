#include "Dog.hpp"

Dog::Dog()
{
	this->brain = new Brain();
	std::cout<<"Dog: Constructor called.\n";
	this->type = "Dog";
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog: Copy Constructor called.\n";
	this->brain = new Brain();
	*this = copy;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog : Destructor called.\n";
}

Dog& Dog ::operator=(const Dog& copy)
{
	Animal::type = copy.type;
    *this->brain = *copy.brain;
	return(*this);
}

void Dog::makeSound ()const
{
	 std::cout << "Hav Hav" << std::endl;
}

std::string  *Dog::getBrain() const
{
	return (this->brain->ideas);
}
