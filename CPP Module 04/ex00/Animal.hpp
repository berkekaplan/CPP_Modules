#pragma once

#include <iostream>
#include <string.h>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal &operator =(const Animal& copy);
		virtual void makeSound()const;
		std::string getType()const;
};
