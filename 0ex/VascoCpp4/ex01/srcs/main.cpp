
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define N_ANIMALS 4

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Array of Animals]" << std::endl;
		const Animal* animals[N_ANIMALS];
		for (int k = 0; k < N_ANIMALS; k++) {
			if (k < N_ANIMALS / 2)
				animals[k] = new Dog();
			else
				animals[k] = new Cat();
		}
		for (int k = 0; k < N_ANIMALS; k++) {
			std::cout << "[" << animals[k]->getType() << "] ";
			animals[k]->makeSound();
		}
		for (int k = 0; k < N_ANIMALS; k++)
			delete animals[k];
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Deep copy: copy constructor]" << std::endl;
		Dog d1;
		d1.getBrain().setIdea("Chase the cat", 0);
		Dog d2(d1);
		d1.getBrain().setIdea("Eat the bone", 0);
		std::cout << "d1 idea: " << d1.getBrain().getIdea(0) << std::endl;
		std::cout << "d2 idea: " << d2.getBrain().getIdea(0) << std::endl;
		std::cout << "Different brains: "
			<< (&d1.getBrain() != &d2.getBrain() ? "yes" : "no") << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Deep copy: assignment operator]" << std::endl;
		Cat c1;
		Cat c2;
		c1.getBrain().setIdea("Sleep all day", 0);
		c2 = c1;
		c1.getBrain().setIdea("Knock things off the table", 0);
		std::cout << "c1 idea: " << c1.getBrain().getIdea(0) << std::endl;
		std::cout << "c2 idea: " << c2.getBrain().getIdea(0) << std::endl;
		std::cout << "Different brains: "
			<< (&c1.getBrain() != &c2.getBrain() ? "yes" : "no") << std::endl;
	}

	std::cout << "-------------------------" << std::endl;

	{
		std::cout << "[Brain out of range]" << std::endl;
		Dog d;
		d.getBrain().setIdea("Ignored", BRAIN_SIZE);
		std::cout << "Idea at " << BRAIN_SIZE << ": \""
			<< d.getBrain().getIdea(BRAIN_SIZE) << "\"" << std::endl;
	}

	return 0;
}
