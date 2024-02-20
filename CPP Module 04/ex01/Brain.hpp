#pragma once

#include <iostream>

class Brain
{
    public:
		std::string ideas[100];
		Brain();
		Brain(const Brain& copy);
		Brain &operator=(const Brain& copy);
		virtual ~Brain();
};
