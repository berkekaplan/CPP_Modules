#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	private:
        Brain *brain;
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog &operator= (const Dog& copy);
		void makeSound()const;
		std::string *getBrain() const;

};
