#include"Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat: Constructor called.\n";
	this->type = "Cat";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat: Copy Constructor called.\n";
	*this = copy;
}

Cat::~Cat(){
	std::cout << "Cat: Destructor called.\n";

}

Cat& Cat ::operator =(const Cat& copy)
{
	Animal::type = copy.type;
	return(*this);
}

void Cat::makeSound ()const
{
	 std::cout << "Miyavvv" << std::endl;
}
