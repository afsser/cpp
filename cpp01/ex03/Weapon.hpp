#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>


# define BLUE "\033[34;1m"
# define GREEN "\033[32;1m"
# define RED "\033[31;1m"
# define YELLOW "\033[33;1m"
# define ORANGE "\033[38;5;208m"
# define CYAN "\033[36;1;3;208m"
# define WHITE "\033[37;1;4m"
# define END "\033[0m"

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType() const;
	void setType(std::string type);
};


#endif