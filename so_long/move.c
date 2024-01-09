#include "so_long.h"

void	move_w(t_data *data)
{
	int		h;
	int		w;
	char	cnt;

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
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h - 1][w] = 'P';
	data->cnt++;
	data->pos_h--;
	draw_map(*data);
	cnt = data->cnt + '0';
	write(1, "cnt : ", 6);
	write(1, &cnt, 1);	
	write(1, "\n", 1);
}

void	move_s(t_data *data)
{
	int		h;
	int		w;
	char	cnt;

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
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h + 1][w] = 'P';
	data->cnt++;
	data->pos_h++;
	draw_map(*data);
	cnt = data->cnt + '0';
	write(1, "cnt : ", 6);
	write(1, &cnt, 1);	
	write(1, "\n", 1);
}

void	move_a(t_data *data)
{
	int		h;
	int		w;
	char	cnt;

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
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h][w - 1] = 'P';
	data->cnt++;
	data->pos_w--;
	draw_map(*data);
	cnt = data->cnt + '0';
	write(1, "cnt : ", 6);
	write(1, &cnt, 1);	
	write(1, "\n", 1);
}

void	move_d(t_data *data)
{
	int		h;
	int		w;
	char	cnt;

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
		terminate(data);
	}
	data->map[h][w] = '0';
	data->map[h][w + 1] = 'P';
	data->cnt++;
	data->pos_w++;
	draw_map(*data);
	cnt = data->cnt + '0';
	write(1, "cnt : ", 6);
	write(1, &cnt, 1);	
	write(1, "\n", 1);
}