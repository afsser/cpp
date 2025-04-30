#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>


class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);
		void announce(void) const;
		void setName(const std::string &newName);
		std::string getName(void) const;
	};	
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);

#endif