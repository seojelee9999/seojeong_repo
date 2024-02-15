#include "so_long.h"

void	draw_map(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			draw_extends(data, i, j);
			j++;
		}
		i++;
	}
	write(1, "cnt :",5);
	ft_putnbr(data.cnt);
	write(1, "\n", 1);
}

void	draw_extends(t_data data, int i, int j)
{
	if (data.map[i][j] == 'C')
		mlx_put_image_to_window(data.mlx, data.win, data.img.feed, \
			64 * j, 64 * i);
	if (data.map[i][j] == 'E')
		mlx_put_image_to_window(data.mlx, data.win, data.img.exit, \
			64 * j, 64 * i);
	if (data.map[i][j] == 'P')
		mlx_put_image_to_window(data.mlx, data.win, data.img.dol, \
			64 * j, 64 * i);
	if (data.map[i][j] == '1')
		mlx_put_image_to_window(data.mlx, data.win, data.img.wall, \
			64 * j, 64 * i);
	if (data.map[i][j] == '0')
		mlx_put_image_to_window(data.mlx, data.win, data.img.street, \
			64 * j, 64 * i);
}

void	terminate(t_data *data)
{
	write(1, "exit", 4);
	mlx_destroy_window(data->mlx, data->win);
	free_result(data->map, data->map_h);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		move_w(data);
	else if (keycode == KEY_S)
		move_s(data);
	else if (keycode == KEY_A)
		move_a(data);
	else if (keycode == KEY_D)
		move_d(data);
	else if (keycode == KEY_ESC)
		terminate(data);
	return (0);
}