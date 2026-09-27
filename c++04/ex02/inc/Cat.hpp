#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
    protected:
        Brain *_brain;

    public:
        Cat();
        Cat(Cat const &other);
        Cat &operator=(Cat const &other);
        virtual ~Cat();

        virtual void makeSound() const;
        void setIdea(int index, std::string const &idea);
        std::string getIdea(int index) const;
};

#endif