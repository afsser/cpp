#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

static int	open_file(std::string infileName, std::string outfileName, std::ifstream *infile, std::ofstream *outfile)
{
	(*infile).open(infileName, std::fstream::in);
	(*outfile).open(outfileName, std::fstream::out);
	if (!infile || !outfile)
	{
		std::cerr << "Failed to open files" << std::endl;
		(*infile).close();
		(*infile).close();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	copy_and_replace(std::ifstream *infile, std::ofstream *outfile, std::string str_sub, std::string str_add)
{
	std::string::size_type	i;
	std::string::size_type	i;
	std::string				line;
	while (getline(*infile, line))
	{
		
	}
	

}

int	main(int argc, char **argv)
{
	std::string 	str_sub = argv[2];
	std::string		str_add = argv[3];
	std::string 	infileName = argv[1];
	std::string		outfileName;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
		return (std::cout << "Wrong number of arguments\n./ft_sed <file> <s1> <s2>" << std::endl, EXIT_FAILURE);
	outfileName = infileName + ".replace";
	if (open_file(infileName, outfileName, &infile, &outfile))
		return (EXIT_FAILURE);
	copy_and_replace(&infile, &outfile, str_sub, str_add);
	infile.close();
	outfile.close();

	std::size_t found = infileName.find_first_of(str_sub[0]);
	return (EXIT_SUCCESS);	
}
