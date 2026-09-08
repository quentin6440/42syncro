NAME = phonebook

INCLUDE				= include/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= c++
CFLAGS				= -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)
RM 					= rm -f

SRC						= main.cpp Phonebook.cpp Contact.cpp utils.cpp

OBJ 					= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all:					$(NAME)

$(NAME):				$(OBJ)
						@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
						@echo "Phonebook compiled, launch with /> ./$(NAME)"

$(OBJ_DIR)%.o:			$(SRC_DIR)%.cpp
						@mkdir -p $(OBJ_DIR)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re