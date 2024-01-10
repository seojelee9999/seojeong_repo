#include "so_long.h"

void	so_error(char *av)
{
	write(1, "Error\n", 6);
	write(1, av, ft_strlen(av));
	exit(1);
}
