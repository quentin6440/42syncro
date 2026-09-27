#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#include <iostream>

int main()
{
    std::cout << "===== POLYMORPHISM =====" << std::endl;

    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << "===== ARRAY =====" << std::endl;

    const int size = 4;
    AAnimal* animals[size];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}
