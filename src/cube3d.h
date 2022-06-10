#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libs/mlx/mlx.h"
# include <stdio.h>
# include "libs/libft/libft.h"
# include "constructor/constructor.h"
# include "display/display.h"
# include "control/control.h"
# include "utils/utils.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define MOVE_DISTANCE 25
# define MINIMAP_SIZE 10
# define TILE_SIZE 100
# define FOV 90

/*
	X Y for positions & vectors
*/
typedef struct	s_vect
{
	double	x;
	double	y;
}	t_vect;

/*
	Color aRGB
	!! keep order of the struct
*/
typedef	struct	s_color
{
	char	b;
	char	g;
	char	r;
	char	a;
}	t_color;

typedef struct s_util
{
	t_color	minimap[3];
}	t_utils;


/* 
	Contains color matrix map of textures 
	member of a t_map struct
*/
typedef struct	s_textures
{
	t_color	**north;
	t_color	**south;
	t_color	**west;
	t_color	**east;

}	t_textures;

/*
	Contais 3D world enviromet data
*/
typedef struct	s_map
{
	char		**bit_map;
	t_textures	textur;
	t_color		ceiling;
	t_color		floor;
}	t_map;

/*
	Player position in a world data
*/
typedef struct	s_player
{
	t_vect	pos;
	t_vect	vect;
}	t_player;

/**
* @brief video rendering data - mlx image and 
* @param img pointer to image (image header) - used in mlx_img_put
* @param img_matrix used to access img_data. 2D array contains 
					type casted pointers to img_data pixels
*/
typedef struct	s_video
{
	void	*img;
	t_color	***img_matrix;
}	t_video;

/*
	MLX Windowing library
*/
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

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
