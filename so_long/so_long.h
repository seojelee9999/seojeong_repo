#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
//# include "mlx.h"

typedef struct s_img{
	void	*wall;
	void	*dol;
	void	*exit;
	void	*street;
	void	*feed;
}	t_img;
typedef struct s_data{
	int		pos_h;
	int		pos_w;
	int		map_w;
	int		map_h;
	t_img	img;
	char	**map;
	char	*line;
	void	*win;
	void	*mlx;
	int		cnt;
	int		c;
	int		e;
	int		p;
}	t_data;
void	check(int ac, char **av);
void	so_error(char *av);
int		so_strncmp(char *s1, char *s2, int n);
void	init_map(int fd, t_data *data);
void	init_cpe(t_data *data);
void	set_cpe(t_data *data, char cpe);
void	check_map(t_data *map);
void	check_rec(t_data *map);
int		num_words(char const *s, char c);
void	r_write(char *result, char const *s, int start, int i);
int		free_result(char **result, int r_index);
int		allocate(char **result, char const *s, char c);
char	**ft_split(char const *s, char c);
void	check_wall(t_data *map);
void	check_new_line(t_data *map);
void	set_pos(t_data *data);
int		dfs_valid(t_data *map, int y, int x);
void	check_valid(t_data *map);
char	*ft_strdup(char *ch);
void	set_img(t_data *data);
void	draw_map(t_data data);
void	draw_extends(t_data data, int i, int j);
int		key_press(int keycode, t_data *data);
void	terminate(t_data *data);
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);
#endif
