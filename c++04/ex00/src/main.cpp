#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

#include <iostream>

int main()
{
    std::cout << std::endl;

    std::cout << "====================== NORMAL POLYMORPHISM TEST ======================" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    std::cout << animal->getType() << " says: ";
    animal->makeSound();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << "====================== WRONG POLYMORPHISM TEST =======================" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << wrongAnimal->getType() << " says: ";
    wrongAnimal->makeSound();

    std::cout << wrongCat->getType() << " says: ";
    wrongCat->makeSound();

    std::cout << std::endl;

    delete wrongAnimal;
    delete wrongCat;

    std::cout << std::endl;

    std::cout << "=============== COPY CONSTRUCTOR / ASSIGNMENT OPERATOR TEST ===============" << std::endl;

    Dog dog1;
    Dog dog2(dog1);       // copy constructor
    Dog dog3;
    dog3 = dog1;          // assignment operator
 
    //dog3 = dog3;          // self-assignment, wont compile with -Werror

    std::cout << std::endl;


    return 0;
}
