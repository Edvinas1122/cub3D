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
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_color;

typedef struct s_utils
{
	t_color	minimap[3];
	int		minimap_size;
}	t_utils;


/* 
	texture data
*/
typedef struct	s_texture
{
	t_color	***matx;
	int 	height;
	int		width;
}	t_texture;

/*
	Contais 3D world enviromet data
*/
typedef struct	s_map
{
	char		**bit_map;
	t_texture	north;
	t_texture	south;
	t_texture 	west;
	t_texture	east;
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


/* 
	Ussed in diyplay only
*/
/*
	Raycast ray data;
*/
typedef struct s_raycast
{
	t_vect	ray_dir;
	t_vect	target;
	t_vect	perp;
	t_vect	impact;
	double	distance;
	int		v_line_ct;
	int		cardinal_direction; //NO:1 SO:2 WE:3 EA:4
}	t_raycast;

// Konstantin comment here
/**
 @param angle -
 @param dist_to_vert @param dist_to_hor -
 @param vert_factor @param hor_factor -
*/
typedef struct s_intersect
{
	double	angle;
	double	dist_to_vert;
	double	dist_to_hor;
	double	vert_factor;
	double	hor_factor;
}	t_intersect;


/**
 @param ray_dir vector of current cast direction
 @param target	e
 @param impact	position where ray hits a wall
 @param v_line_ct count of which vertical line we refer
*/
typedef struct s_wall
{
	int		y;
	double	size;
	int		offset;
	int		start;
	int		end;
	t_color color;
}	t_wall;

typedef struct s_line
{
	t_texture	texture;
	double		strech_factor;
	int			horizontal_offset;
	int			vertical_offset;
}	t_line;

/* 
	Ussed in diyplay only
*/

int	main(int argc, char **argv);

#endif
