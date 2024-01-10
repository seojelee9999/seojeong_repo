#include "so_long.h"

void	check(int ac, char **av)
{
	if (ac != 2)
		so_error("argments is not 2");
	if (so_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
		so_error("file type is not .ber");
}

void	check_map(t_data *map)
{
	if (map->p != 1)
		so_error("start point is not 1");
	if (map->e != 1)
		so_error("exit is not 1");
	if (map->c < 1)
		so_error("C is less than 1");
	map->map = ft_split(map->line, '\n');
	check_rec(map);
	check_wall(map);
	check_new_line(map);
	set_pos(map);
	check_valid(map);
}

void	check_rec(t_data *map)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (width != ft_strlen(map->map[i]))
			so_error("width is incorrect");
		i++;
	}
	map->map_h = i;
	map->map_w = width;
}

void	check_wall(t_data *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
		if (map->map[0][i++] != '1')
			so_error("last col is not 1");
	i = 0;
	while (map->map[map->map_h - 1][i])
		if (map->map[map->map_h - 1][i++] != '1')
			so_error("last col is not 1");
	i = 0;
	while (map->map[i])
		if (map->map[i++][0] != '1')
			so_error("first row is not 1");
	i = 0;
	while (map->map[i])
		if (map->map[i++][map->map_w - 1] != '1')
			so_error("last row is not 1");
}

void	check_new_line(t_data *map)
{
	int	i;

	if (map->line[0] == '\n')
		so_error("start new line");
	i = 0;
	while (map->line[i + 1])
	{
		if (!so_strncmp(&map->line[i], "\n\n", 2))
			so_error("successive new line");
		i++;
	}
	free(map->line);
	map->line = 0;
}
