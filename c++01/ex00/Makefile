NAME = zombies

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = $(SRC:%.cpp=build/%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compilation OK"

build/%.o:	%.cpp
	@mkdir -p build
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf build

fclean:	clean
	@rm -f $(NAME)

re: fclean all