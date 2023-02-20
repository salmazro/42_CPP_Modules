#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include <iostream>

class Brain
{
	protected:
		std::string idea[100];

	public:
		Brain();
		Brain(Brain& b);
		Brain& operator=(Brain const &b);
		~Brain();
		void ideaGeneration(int i, std::string idea);
		std::string const  &getIdea (int i) const;
};


#endif
