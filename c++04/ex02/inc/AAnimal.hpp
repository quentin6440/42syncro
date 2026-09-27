#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(AAnimal const &other);
        AAnimal &operator=(AAnimal const &other);
        virtual ~AAnimal();

        AAnimal(std::string type);
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif