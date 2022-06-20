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
		dir.y = -1;
	else if (*c == 'W')
		dir.x = 1;
	else if (*c == 'S')
		dir.y = 1;
	else if (*c == 'E')
		dir.x = -1;
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
	Initiates t_data struct and promts a window;
*/
void	constructor(t_data *data, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = start_window();
	open_cub_file(argv[1], data);
	data->video = set_video_window(data->mlx);
	data->player = set_player(data->map.bit_map, TILE_SIZE);
	data->scalefactor = (double)SCREEN_WIDTH / 1600;
	data->util = set_utils(data);
	set_sprites(data, "./assets/sprite_info.ini");
	data->player.dash_cooldown = 0;
	data->potion.position.x = 150;
	data->potion.position.y = 150;
}
