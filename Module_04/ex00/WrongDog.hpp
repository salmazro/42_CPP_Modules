#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(WrongDog& wd);
		WrongDog& operator=(WrongDog& wd);
		~WrongDog();
		void makeSound() const;
};
#endif
