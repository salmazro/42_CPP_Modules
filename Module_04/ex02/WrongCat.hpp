#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain *brain;
	public:
		WrongCat();
		WrongCat(WrongCat& wc);
		WrongCat& operator=(WrongCat& wc);
		~WrongCat();
		void makeSound() const;
		Brain *getBrain() const;
};

#endif
