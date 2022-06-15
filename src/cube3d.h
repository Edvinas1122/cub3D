#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "recurrent.h"
# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"
# include "constructor/constructor.h"
# include "control/control.h"
# include "utils/utils.h"
# include "display/display.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define MOVE_DISTANCE 25
# define TILE_SIZE 100
# define FOV 90

/*
	Main data stack segment
*/
typedef struct	s_data
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	t_video		video;
	t_utils		util;
}	t_data;


int	main(int argc, char **argv);

#endif
