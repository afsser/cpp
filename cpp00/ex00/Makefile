CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

NAME = Megaphone

SRCS = megaphone.cpp

OBJS = $(addprefix $(BIN_DIR), $(SRCS:%.cpp=%.o))

INCLUDES = ./includes/

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
	@echo $(GREEN)"|          $(NAME) compiled           |"$(END)
	@echo $(GREEN)"-----------------------------------------"$(END)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(BIN_DIR)%.o: ./%.cpp
	@echo $(CYAN)".\n"$(END)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@rm -rf $(BIN_DIR)
	@echo	$(RED)"$(NAME) objects removed"$(END)

fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"$(NAME) removed"$(END)

re: fclean all

.PHONY: all clean fclean re