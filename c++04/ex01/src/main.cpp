#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#include <iostream>

int main()
{
std::cout << "===== DEEP COPY =====" << std::endl;

Dog dog1;
dog1.setIdea(0, "I love bones");

Dog dog2(dog1);
dog2.setIdea(0, "I hate cats");

std::cout << "dog1: " << dog1.getIdea(0) << std::endl;
std::cout << "dog2: " << dog2.getIdea(0) << std::endl;

Cat cat1;
cat1.setIdea(0, "I love sleeping");

Cat cat2(cat1);
cat2.setIdea(0, "I love playing");

std::cout << "cat1: " << cat1.getIdea(0) << std::endl;
std::cout << "cat2: " << cat2.getIdea(0) << std::endl;


std::cout << std::endl;
std::cout << "===== ANIMAL ARRAY =====" << std::endl;

const int size = 4;
Animal* animals[size];

for (int i = 0; i < size / 2; ++i)
    animals[i] = new Dog();

for (int i = size / 2; i < size; ++i)
    animals[i] = new Cat();

for (int i = 0; i < size; ++i)
    animals[i]->makeSound();

for (int i = 0; i < size; ++i)
    delete animals[i];

return 0;


}