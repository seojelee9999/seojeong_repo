#include "so_long.h"

void	check_valid(t_data *map)
{
	int		i;
	t_data	tmp;

	tmp.c = map->c;
	tmp.e = map->e;
	tmp.map = (char **)malloc(sizeof(char *) * map->map_h);
	if (!tmp.map)
		so_error("fail malloc");
	i = 0;
	while (i < map->map_h)
	{
		tmp.map[i] = ft_strdup(map->map[i]);
		i++;
	}
	dfs_valid(&tmp, map->pos_h, map->pos_w);
	if (tmp.c != 0 || tmp.e != 0)
		so_error("cant arrive exit");
	free_result(tmp.map, map->map_h);
}

int	dfs_valid(t_data *map, int y, int x)
{
	if (map->map[y][x] == '1')
		return (0);
	if (map->map[y][x] == 'C')
		map->c--;
	if (map->map[y][x] == 'E')
	{
		map->e = 0;
		return (0);
	}
	map->map[y][x] = '1';
	if (dfs_valid(map, y - 1, x))
		return (1);
	if (dfs_valid(map, y + 1, x))
		return (1);
	if (dfs_valid(map, y, x + 1))
		return (1);
	if (dfs_valid(map, y, x - 1))
		return (1);
	return (0);
}
