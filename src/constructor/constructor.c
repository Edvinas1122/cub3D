#include "constructor.h"

/*
	Finds player in bitmap - sets coordinates & vector
*/
static t_vect	set_player_vector(char **bit_map, char *directions)
{
	char	*c;
	t_vect	dir;

	ft_bzero(&dir, sizeof(t_vect));
	c = find_char(bit_map, directions);
	if (*c == 'N')
	{
		dir.x = 1;
		dir.y = 0;
	} 
	else if (*c == 'W')
	{
		dir.x = 0;
		dir.y = -1;
	}
	else if (*c == 'S')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else if (*c == 'E')
	{
		dir.x = 0;
		dir.y = 1;
	}
	return (dir);
}

/* 
	Initiates t_player struct - sets his position and vector;
	Multiples bit map coordinate into tile size coordinate
*/
static t_player	set_player(char **bit_map, int tile_size)
{
	t_player	player;

	player.pos = find_char_cordinates(bit_map, "NEWS");
	player.pos.x = (player.pos.x * tile_size) + (tile_size / 2);
	player.pos.y = (player.pos.y * tile_size) + (tile_size / 2);
	player.vect = set_player_vector(bit_map, "NEWS");
	return (player);
}

/* 
	Starts windowing procedure;
*/
static t_mlx	start_window(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	return (mlx);
}

/*
	Sets additional data like minimap color
	To avoid additional loops in video render
*/
static t_utils set_utils(void)
{
	t_utils utils;

	utils.minimap[0] = set_color(0, 40, 40, 40);
	utils.minimap[1] = set_color(0, 120, 120, 120);
	utils.minimap[2] = set_color(0, 255, 0, 0);
	return (utils);
}

/*
	Initiates t_data struct and promts a window;
*/
void	constructor(t_data *data, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	open_cub_file(argv[1], data);
	data->player = set_player(data->map.bit_map, TILE_SIZE);
	data->util = set_utils();
	data->mlx = start_window();
	data->video = set_video_window(data->mlx);
}
