#include "Cat.hpp"

Cat::Cat()
{
	this->brain = new Brain();
	std::cout<<"Cat: Constructor called.\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat: Copy Constructor called.\n";
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat: Destructor called.\n";
}

Cat& Cat ::operator =(const Cat& copy)
{
	Animal::type = copy.type;
    *this->brain = *copy.brain;
	return(*this);
}

void Cat::makeSound ()const
{
	 std::cout << "Miyavvv" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}
