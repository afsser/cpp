NAME = bureaucrat

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

# Files
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(addprefix $(BIN_DIR), $(SRCS:%.cpp=%.o))

INCLUDES = .

BIN_DIR = ./bin/

# Colors
BLUE = "\033[34;1m"
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
END = "\033[0m"

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(NAME): $(OBJS)
	@echo $(GREEN)"-----------------------------------------"$(END)
	@echo $(GREEN)"|               COMPILED                |"$(END)
	@echo $(GREEN)"-----------------------------------------"$(END)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BIN_DIR)%.o: ./%.cpp
	@echo $(CYAN)".\n"$(END)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -f $(OBJS) && echo	$(RED)"$(NAME) objects removed"$(END)
	@rm -rf $(BIN_DIR) 

fclean: clean
	@rm -f $(NAME) && echo $(RED)"$(NAME) removed"$(END)

re: fclean all

.PHONY: all clean fclean re