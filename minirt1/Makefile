NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
LIBFT = ./libft/libft.a
LIBS = $(LIBFT) -lm

SRC = main.c draw.c events.c util.c vectors/vec_basic.c

OBJ = $(SRC:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C ./libft/

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj
	@make -C ./libft/ clean 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean 2>/dev/null || true

re: fclean all