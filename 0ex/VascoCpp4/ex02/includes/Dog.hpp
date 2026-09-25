
#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal {

	Brain* brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;

		Brain& getBrain();
		const Brain& getBrain() const;
};

#endif // DOG_HPP
