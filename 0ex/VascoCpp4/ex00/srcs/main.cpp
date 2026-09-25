
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define N_ANIMALS 4

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "-------------------------" << std::endl;

	{
		const WrongAnimal* wa = new WrongAnimal();
		const WrongAnimal* wc = new WrongCat();

		std::cout << wa->getType() << " " << std::endl;
		std::cout << wc->getType() << " " << std::endl;

		wa->makeSound();
		wc->makeSound();

		delete wa;
		delete wc;
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Copy constructor]" << std::endl;
		Dog d1;
		Dog d2(d1);
		std::cout << d2.getType() << ": ";
		d2.makeSound();
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Assignment operator]" << std::endl;
		Cat c1;
		Cat c2;
		c2 = c1;
		std::cout << c2.getType() << ": ";
		c2.makeSound();
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Polymorphism through a reference]" << std::endl;
		Cat c;
		const Animal& ref = c;
		std::cout << ref.getType() << ": ";
		ref.makeSound();
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Array of Animal pointers]" << std::endl;
		const Animal* animals[N_ANIMALS] = { new Dog(), new Cat(), new Animal(), new Dog() };
		for (int k = 0; k < N_ANIMALS; k++) {
			std::cout << "[" << animals[k]->getType() << "] ";
			animals[k]->makeSound();
		}
		for (int k = 0; k < N_ANIMALS; k++)
			delete animals[k];
	}

	return 0;
}
