#ifndef CUBE3D_COMMON_H
# define CUBE3D_COMMON_H
# define SCREEN_WIDTH 1600

# include "cube3d.h"

typedef struct s_door
{
	int	solid;
	int	closed_percentage;
	int	moving;
}	t_door;

/*
	X Y for positions & vectors
*/
typedef struct s_vect
{
	double	x;
	double	y;
}	t_vect;

/*
	Color aRGB
	!! keep order of the struct
*/
typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_color;

/* 
	texture data
*/
typedef struct s_texture
{
	void	*img_header;
	t_color	***matx;
	int		height;
	int		width;
}	t_texture;

/*
	Contais 3D world enviromet data
*/
typedef struct s_map
{
	char		**bit_map;
	t_door		**doormap;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_texture	door;
	t_color		ceiling;
	t_color		floor;
	double		z_buffer[SCREEN_WIDTH];
}	t_map;

/**
* @brief video rendering data - mlx image and 
* @param img pointer to image (image header) - used in mlx_img_put
* @param img_matrix used to access img_data. 2D array contains 
					type casted pointers to img_data pixels
*/
typedef struct s_video
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

// typedef struct s_texture
// {
// 	t_color	***matx;
// 	int		width;
// 	int		height;
// }	t_texture;

typedef struct s_sprite_anim
{
	t_texture	*img_arr;
}	t_sprite_anim;

/*
	Entity
*/
typedef struct s_entity
{
	int				id;
	int				anim_info;
	t_vect			position;
	double			scale;
	int				frames;
	t_vect			on_screen;
	double			distance;
	int				obj_count;
}	t_entity;

#endif 