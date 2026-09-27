#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);
        ~Brain();

        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};

#endif