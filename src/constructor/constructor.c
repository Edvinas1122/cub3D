#include "constructor.h"

static t_vect	set_player_vector(char **bit_map, char *directions)
{
	char	*c;
	t_vect	dir;

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
*/
static t_player	set_player(char **bit_map)
{
	t_player	player;

	player.pos = find_char_cordinates(bit_map, "NEWS");
	player.vect = set_player_vector(bit_map, "NEWS");
	return (player);
}

static t_mlx	*start_window(char **argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	return (mlx);
}

/* 
	Initiates t_data struct and promts a window;
*/
void	constructor(t_data *data, char **argv)
{
	data->map = open_cub_file(argv[1]);
	data->player = set_player(data->map.bit_map);
	data->mlx = start_window();
	data->video = set_video_window(data->mlx);
}