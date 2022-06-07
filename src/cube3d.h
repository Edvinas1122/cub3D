#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include "libs/mlx/mlx.h"
# include <mlx.h>
# include "libs/libft/libft.h"
# include "constructor/constructor.h"
# include "utils/utils.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

/*
	X Y for positions & vectors
*/
typedef struct	s_vect
{
	int	x;
	int	y;
}	t_vect;

/*
	Color RGB T?
*/
typedef	struct	s_color
{
	char	r;
	char	g;
	char	b;
	char	t;
}	t_color;

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

/*
	Video render data
*/
typedef struct	s_video
{
	void	*img_ptr;
	char	*img;
	char	***img_matrix;
	int		img_bp;
	int		img_sl;
	int		img_e;
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
	t_mlx		*mlx;
	t_video		*video;

}	t_data;

int	main(int argc, char **argv);

/*
	Hooks
*/
int	mhook(int button, int x, int y, void *param);
int	khook(int key, void *param);

#endif
