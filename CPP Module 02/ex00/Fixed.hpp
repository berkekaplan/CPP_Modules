#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed;
		static const int fract_val = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed& new_fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif