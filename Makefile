NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC = \
	src/main.c \
	src/parsing/util.c \
	src/parsing/free.c \
	src/parsing/init_struct.c \
	src/parsing/parsing.c \
	src/parsing/texture.c \
	src/parsing/line.c \
	src/parsing/valid.c \
	src/parsing/player.c \
	src/parsing/parse_map.c \
	src/parsing/check_texture.c \
	src/parsing/check_map.c \
	src/parsing/debug.c \
	src/window/window.c \
	src/window/load_texture.c \
	src/window/key.c \
	src/window/game.c \
	src/window/collision.c \
	src/raycasting/raycasting.c \
	src/raycasting/util_raycasting.c \
	src/raycasting/draw.c \
	src/raycasting/util_draw.c \
	src/raycasting/wall.c \

SRC_BONUS = \
	src/main.c \
	src/parsing/util.c \
	src/parsing/free.c \
	src/parsing/init_struct.c \
	src/parsing/parsing.c \
	src/parsing/texture.c \
	src/parsing/line.c \
	src/parsing/valid.c \
	src/parsing/player.c \
	src/parsing/parse_map.c \
	src/parsing/check_texture.c \
	src/parsing/check_map.c \
	src/parsing/debug.c \
	src/window/load_texture.c \
	src/window/key.c \
	src/window/game.c \
	src/window/collision.c \
	src/raycasting/raycasting.c \
	src/raycasting/util_raycasting.c \
	src/raycasting/draw.c \
	src/raycasting/util_draw.c \
	src/raycasting/wall.c \
	src/window/bonus/window_bonus.c \
	src/window/bonus/border_bonus.c \
	src/window/bonus/minimap_bonus.c \
	src/window/bonus/player_bonus.c \

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:src/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -lXext -lX11 -lm -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLX_LIB) -lXext -lX11 -lm -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
