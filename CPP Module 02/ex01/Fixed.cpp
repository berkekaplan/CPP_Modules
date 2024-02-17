#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed = 0;
    std::cout << "Default consturctor called\n";
}

Fixed::Fixed(const int fi)
{
    std::cout << "Int constructor called\n";
	this->fixed = (fi * 256);
}

Fixed::Fixed(const float ff)
{
    std::cout << "Float constructor called\n";
	this->fixed = roundf(ff * 256);
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called\n"; 
        *this = copy;
}

int	Fixed::getRawBits() const 
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &newFixed)
{
    std::cout << "Copy assignment operator called\n";
    
    if(this != &newFixed)
    {
        this->fixed = newFixed.fixed;
    }
    
    return(*this);
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixed / 256);
}

int Fixed::toInt( void ) const
{
    return (this->fixed / 256);
}

std::ostream &operator<<(std::ostream &o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}