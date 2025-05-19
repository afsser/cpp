#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"
# include <string>

class Brain {
private:
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& copy);
	Brain &operator=(const Brain& copy);
	std::string *getIdeas(void) const;
};

#endif