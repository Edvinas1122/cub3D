#ifndef CUBE3D_RECURRENT
# define CUBE3D_RECURRENT
# define SCREEN_WIDTH 1920

#include "cube3d.h"

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

/* 
	texture data
*/
typedef struct	s_texture
{
	void	*img_header;
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
	double		z_buffer[SCREEN_WIDTH];
}	t_map;

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

#endif 