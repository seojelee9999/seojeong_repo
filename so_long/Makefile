NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx_opengl_20191021
MLX_FLAG = -lmlx -framework OpenGL -framework AppKit
SRCS = src/check.c src/check2.c src/draw.c src/error.c \
	src/get_next_line_utils.c src/get_next_line.c src/init_map.c \
	src/move.c src/so_long.c src/split.c src/util.c
SRCS_DIR = ./src
MLX_NAME = mlx
MLX_DIR = ./minilibx_opengl_20191021
OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) -L$(MLX_DIR) -l$(MLX_NAME) $(MLX_FLAG) $^ -o $@
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
