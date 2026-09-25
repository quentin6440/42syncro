
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define BRAIN_SIZE 100

class Brain {

	std::string ideas[BRAIN_SIZE];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(const std::string& idea, int index);
		const std::string& getIdea(int index) const;
};

#endif // BRAIN_HPP
