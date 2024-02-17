#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::Fixed(const int fi)
{
	this->fixed = (fi * 256);
}

Fixed::Fixed(const float ff)
{
	this->fixed = roundf(ff * 256);
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const& fixed)
{
	if (this != &fixed)
		this->fixed = fixed.fixed;
	return (*this);
}

bool	Fixed::operator>(Fixed const& fixed) const
{
	return (this->fixed > fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const& fixed) const
{
	return (this->fixed >= fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const& fixed) const
{
	return (this->fixed < fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const& fixed) const
{
	return (this->fixed <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const& fixed) const
{
	return (this->fixed == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const& fixed) const
{
	return (this->fixed != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const& fixed)
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(Fixed const& fixed)
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(Fixed const& fixed)
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(Fixed const& fixed)
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(this->toFloat());
	this->fixed++;
	return (ret);
}

Fixed	&Fixed::operator--()
{
	this->fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(this->toFloat());
	this->fixed--;
	return (ret);
}

int	Fixed::getRawBits() const
{
	return (this->fixed);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed / 256);
}

int	Fixed::toInt(void) const
{
	return (this->fixed / 256);
}

Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed&a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed&a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}


std::ostream &operator<<(std::ostream &o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return (o);
}