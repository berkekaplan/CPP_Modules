#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type): type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
    *this = copy;
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& copy)
{
    this->setType(copy.getType());
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return (type);
}

void AAnimal::setType(std::string type)
{
    this->type = type;
}
