#pragma once

#include <iostream>
#include <string.h>

class	WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const	WrongAnimal& copy);
		virtual ~WrongAnimal();
		WrongAnimal &operator =(const	WrongAnimal& copy);
		void makeSound()const;
		std::string getType()const;
};
