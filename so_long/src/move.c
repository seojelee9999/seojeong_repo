#include "so_long.h"

void	move_w(t_data *data)
{
	int		h;
	int		w;

	h = data->pos_h;
	w = data->pos_w;
	if (data->map[h - 1][w] == '1')
		return ;
	if (data->map[h - 1][w] == 'C')
		data->c--;
	if (data->map[h - 1][w] == 'E')
	{
		if (data->c != 0)
			return ;
		data->cnt++;
		write(1, "cnt :",5);
		ft_putnbr(data->cnt);
		write(1, "\n", 1);
		write(1, "successs\n", 9);
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h - 1][w] = 'P';
	data->pos_h--;
	data->cnt++;
	draw_map(*data);
}

void	move_s(t_data *data)
{
	int		h;
	int		w;

	h = data->pos_h;
	w = data->pos_w;
	if (data->map[h + 1][w] == '1')
		return ;
	if (data->map[h + 1][w] == 'C')
		data->c--;
	if (data->map[h + 1][w] == 'E')
	{
		if (data->c != 0)
			return ;
		data->cnt++;
		write(1, "cnt :",5);
		ft_putnbr(data->cnt);
		write(1, "\n", 1);
		write(1, "successs\n", 9);
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h + 1][w] = 'P';
	data->cnt++;
	data->pos_h++;
	draw_map(*data);
}

void	move_a(t_data *data)
{
	int		h;
	int		w;

	h = data->pos_h;
	w = data->pos_w;
	if (data->map[h][w - 1] == '1')
		return ;
	if (data->map[h][w - 1] == 'C')
		data->c--;
	if (data->map[h][w - 1] == 'E')
	{
		if (data->c != 0)
			return ;
		data->cnt++;
		write(1, "cnt :",5);
		ft_putnbr(data->cnt);
		write(1, "\n", 1);
		write(1, "successs\n", 9);
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h][w - 1] = 'P';
	data->cnt++;
	data->pos_w--;
	draw_map(*data);
}

void	move_d(t_data *data)
{
	int		h;
	int		w;

	h = data->pos_h;
	w = data->pos_w;
	if (data->map[h][w + 1] == '1')
		return ;
	if (data->map[h][w + 1] == 'C')
		data->c--;
	if (data->map[h][w + 1] == 'E')
	{
		if (data->c != 0)
			return ;
		data->cnt++;
		write(1, "cnt :",5);
		ft_putnbr(data->cnt);
		write(1, "\n", 1);
		write(1, "successs\n", 9);
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h][w + 1] = 'P';
	data->cnt++;
	data->pos_w++;
	draw_map(*data);
}