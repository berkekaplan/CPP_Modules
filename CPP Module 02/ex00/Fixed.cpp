#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->fixed = 0;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout <<"Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout <<"getRawBits member function called\n";
    return this->fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed = raw;   
}

Fixed &Fixed::operator=(const Fixed& new_fixed)
{
    std::cout << "Copy assignment operator called\n";
    
    if(this != &new_fixed)
    {
        this->fixed = new_fixed.getRawBits();
    }
    
    return *this;
}