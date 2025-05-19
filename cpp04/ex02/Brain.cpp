#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "hmm... I have no idea";
	std::cout << BOLD << "Brain created" << RST << std::endl;
}

Brain::~Brain() {
	std::cout << BOLD << "Brain destroyed" << RST << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << BOLD << "Brain copied" << RST << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain& copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
		std::cout << BOLD << "Brain assigned" << RST << std::endl;
	}
	return *this;
}
std::string *Brain::getIdeas(void) const {
	return ((std::string *)this->_ideas);
}