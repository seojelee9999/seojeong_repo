#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	check(ac, av);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		so_error("file open error!");
	init_map(fd, &data);
	check_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map_w * 64, \
	data.map_h * 64, "so_long");
	set_img(&data);
	draw_map(data);
	mlx_hook(data.win, KEY_RELEASE, 0, &key_press, &data);
	mlx_loop(data.mlx);
}
