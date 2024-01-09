NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
SRCS = check.c check2.c draw.c error.c get_next_line_utils.c \
	get_next_line.c init_map.c move.c so_long.c split.c \
	util.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
%.o : %.c
	$(CC) -c $(CFLAGS) $^ -o $@
$(NAME) : $(OBJS)
	$(CC) -c $(CFLAGS) $(MLX) $^ -o $@
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean fclean re
