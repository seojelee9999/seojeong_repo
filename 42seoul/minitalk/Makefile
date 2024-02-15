NAME_SERVER = server
NAME_CLIENT = client
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_UTIL = util.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_UTIL = $(SRCS_UTIL:.c=.o)

all : $(NAME)
$(NAME) : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJS_UTIL) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@
$(NAME_CLIENT) : $(OBJS_UTIL) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

clean :
		rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTIL)
fclean : clean
		rm -f $(NAME_SERVER) $(NAME_CLIENT)
re : fclean all

.PHONY : all clean fclean re

	