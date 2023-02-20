#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

// int main()
// {
// 	{
// 		const Animal* meta = new Animal();
// 		const Animal* j = new Dog();
// 		const Animal* i = new Cat();
// 		std::cout << "----------------------------------------------------------" << std::endl;
// 		std::cout << j->getType() << " " << std::endl;
// 		std::cout << i->getType() << " " << std::endl;
// 		j->makeSound();
// 		i->makeSound();
// 		meta->makeSound();
// 		std::cout << "----------------------------------------------------------" << std::endl;
// 		delete meta;
// 		delete i;
// 		delete j;
// 		return 0;
// 	}

// 	// {
// 	// 	const WrongAnimal* metaaa = new WrongAnimal();
// 	// 	const WrongAnimal* me = new WrongDog();
// 	// 	const WrongAnimal* he = new WrongCat();
// 	// 	std::cout << "----------------------------------------------------------" << std::endl;
// 	// 	std::cout << me->getType() << " " << std::endl;
// 	// 	std::cout << he->getType() << " " << std::endl;
// 	// 	me->makeSound();
// 	// 	metaaa->makeSound();
// 	// 	he->makeSound();
// 	// 	std::cout << "----------------------------------------------------------" << std::endl;
// 	// 	delete metaaa;
// 	// 	delete he;
// 	// 	delete me;
// 	// 	return 0;
// 	// }
// }

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
	std::cout << "----------------------------------------------------------" << std::endl;

    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();//will output the Dog sound!
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound(); //will output the cat sound!
    std::cout << animal->getType() << " " << std::endl;
    animal->makeSound();//will output animal sound
	std::cout << "----------------------------------------------------------" << std::endl;
 	delete animal;
    delete dog;
    delete cat;

	std::cout << "----------------------------------------------------------" << std::endl;
	// const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();
    delete wc;

    return 0;
}
