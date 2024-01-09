#include "so_long.h"

void	init_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		data->line = ft_strjoin(data->line, line);
		free(line);
		line = get_next_line(fd);
	}
	init_cpe(data);
	i = 0;
	while (data->line[i])
		set_cpe(data, data->line[i++]);
}

void	init_cpe(t_data *data)
{
	data->c = 0;
	data->p = 0;
	data->e = 0;
	data->cnt = 0;
}

void	set_cpe(t_data *data, char cpe)
{
	if (cpe == 'C')
		data->c++;
	if (cpe == 'P')
		data->p++;
	if (cpe == 'E')
		data->e++;
}

void	set_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'E' \
				|| data->map[i][j] == '0' || data->map[i][j] == '1')
				j++;
			else if (data->map[i][j] == 'P')
			{
				data->pos_h = i;
				data->pos_w = j;
				j++;
			}
			else
				so_error("invailid maps");
		}
		i++;
	}
}

void	set_img(t_data *data)
{
	int	width;
	int	height;

	data->img.wall = mlx_xpm_file_to_img \
		(data->mlx, "./images/wall.xpm", &width, &height);
	data->img.dol = mlx_xpm_file_to_img \
		(data->mlx, "./images/dol.xpm", &width, &height);
	data->img.street = mlx_xpm_file_to_img \
		(data->mlx, "./images/street.xpm", &width, &height);
	data->img.exit = mlx_xpm_file_to_img \
		(data->mlx, "./images/exit.xpm", &width, &height);
	data->img.feed = mlx_xpm_file_to_img \
		(data->mlx, "./images/feed.xpm", &width, &height);
}
