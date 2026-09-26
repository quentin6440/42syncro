NAME = clapTrap

CXX = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = inc/
SRC_DIR = src/
OBJ_DIR = build/

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

.PHONY: all clean fclean re run

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "compilation OK, binary created here: ./$(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CXX) $(CFLAGS) -c $< -o $@

run: $(NAME)
	@./$(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
