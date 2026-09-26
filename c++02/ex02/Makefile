NAME = fixedPointNumber

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = inc/
SRC_DIR = src/
OBJ_DIR = build/

SRC = main.cpp Fixed.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

.PHONY: all clean fclean re run

run: $(NAME)
	@./$(NAME)

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "compilation OK, run with: ./$(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re: fclean all
