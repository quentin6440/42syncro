#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(Animal const &other);
        Animal &operator=(Animal const &other);
        virtual ~Animal();

        Animal(std::string type);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif