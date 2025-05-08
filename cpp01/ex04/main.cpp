#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

static int	open_file(std::string infileName, std::string outfileName, std::ifstream *infile, std::ofstream *outfile)
{
	(*infile).open(infileName.c_str(), std::fstream::in);
	(*outfile).open(outfileName.c_str(), std::fstream::out);
	if (!infile->is_open() || !outfile->is_open())
	{
		std::cerr << "Failed to open files" << std::endl;
		(*infile).close();
		(*outfile).close();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	copy_and_replace(std::ifstream *infile, std::ofstream *outfile, std::string str_sub, std::string str_add)
{
	size_t			pos;
	size_t			found;
	std::string		result;
	std::string		line;
	if (str_sub.empty())
	{
		std::cerr << "Empty string to replace" << std::endl;
		return (EXIT_FAILURE);
	}
	while (getline(*infile, line))
	{
		result = "";
		pos = 0;

		while (true)
		{
			found = line.find(str_sub, pos);
			result.append(line, pos, found - pos);
			if (found == std::string::npos)
				break ;
			result.append(str_add);
			pos = found + str_sub.length();
		}
		(*outfile) << result;
		if (!infile->eof())
			(*outfile) << std::endl;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Wrong number of arguments\n./ft_sed <file> <s1> <s2>" << std::endl, EXIT_FAILURE);
	std::string 	str_sub = argv[2];
	std::string		str_add = argv[3];
	std::string 	infileName = argv[1];
	std::string		outfileName;
	std::ifstream	infile;
	std::ofstream	outfile;

	outfileName = infileName + ".replace";
	if (open_file(infileName, outfileName, &infile, &outfile))
		return (EXIT_FAILURE);
	if (copy_and_replace(&infile, &outfile, str_sub, str_add))
		return (EXIT_FAILURE);
	infile.close();
	outfile.close();

	return (EXIT_SUCCESS);	
}
