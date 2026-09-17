NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I minilibx-linux

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

LIBS = $(LIBFT) $(MLX) -lXext -lX11 -lm

SRC = 	main.c \
      	draw.c \
      	events.c \
      	util.c \
		scene.c \
		ray.c \
		sphere.c \
		cylinder.c \
		plane.c \
      	vec_basic.c \
      	vec_math.c \
      	vec_utils.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Compile OK, ready to launch with: ./$(NAME) <scene.rt>"

# Règle spéciale pour débugger avec AddressSanitizer
sanitize: CFLAGS += -g3 -fsanitize=address
sanitize: re
	@echo "Compilation avec -fsanitize=address activée !"

$(LIBFT):
	@make -C ./libft/ > /dev/null

$(MLX):
	@make -C ./minilibx-linux/ > /dev/null 2>&1

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./libft/ clean 2>/dev/null || true
	@make -C ./minilibx-linux/ clean 2>/dev/null || true

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean 2>/dev/null || true

re: fclean all

.PHONY: all clean fclean re sanitize