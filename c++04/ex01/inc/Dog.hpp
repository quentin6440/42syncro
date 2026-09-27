#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    protected:
        Brain *_brain;

    public:
        Dog();
        Dog(Dog const &other);
        Dog &operator=(Dog const &other);
        virtual ~Dog();

        virtual void makeSound() const;

        void setIdea(int index, std::string const &idea);
        std::string getIdea(int index) const;
};

#endif