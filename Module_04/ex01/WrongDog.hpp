#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongDog : public WrongAnimal
{
	private:
		Brain *brain;
	public:
		WrongDog();
		WrongDog(WrongDog& wd);
		WrongDog& operator=(WrongDog& wd);
		~WrongDog();
		void makeSound() const;
		Brain *getBrain() const;
};
#endif
