void RPN::processInput(const std::string &input) {
	// check if there is only numbers between 0 and 10 or + - / * with c++98
	if (input.empty()) {
		std::cerr << "Error: Input is empty." << std::endl;
		return;
	}
	for (int i = 0; input.c_str()[i] != '\0'; i++) {
		char c = input.c_str()[i];
		if (c == ' ')
			continue ;
		if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/') {
			std::cerr << "Error: Invalid character '" << c << "' in input." << std::endl;
			return ;
		}
	}
}