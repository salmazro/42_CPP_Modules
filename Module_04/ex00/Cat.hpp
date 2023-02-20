#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat& c);
		Cat& operator=(Cat& c);
		virtual ~Cat();
		virtual void makeSound() const;
};
#endif
