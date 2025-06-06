#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <cstdlib>

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

#endif

// #ifndef HARL_HPP
// # define HARL_HPP

// # include <string>
// # include <cstdlib>

// # define RED "\033[1;31m"
// # define GRN "\033[1;32m"
// # define RST "\033[0m"

// class Harl
// {
// 	public:
// 		Harl();
// 		~Harl();
// 		void complain(std::string level);

// 	private:
// 		void _debug(void);
// 		void _info(void);
// 		void _warning(void);
// 		void _error(void);
// 		void (Harl::*f[4])();
// 		std::string levels[4];
// };

// #endif