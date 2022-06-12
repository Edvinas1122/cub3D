#ifndef CUBE3D_CONSTRUCTOR_H
# define CUBE3D_CONSTRUCTOR_H

# include "../cube3d.h"
# include "validation/validation.h"

typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_texture	t_texture;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;

/**
	@param img_data pointer to image data - string of color data
					contains string of (aRGB) * total pixel count
	@param img_bp	value of bits per pixel
	@param img_sl	value of width size in bytes
	@param img_e	true or false endian.. ? (dunno what it is)
*/
typedef struct s_tmp_video
{
	char	*img_data;
	int		img_bp;
	int		img_sl;
	int		img_e;
}	t_tmp_video;

/* Struct initiator */
void		constructor(t_data *data, char **argv);
void		destructor(t_data *data);

/* Member in constructor */
void		open_cub_file(char *file_name, t_data *data);
t_video		set_video_window(t_mlx mlx);
t_texture	load_texture_files(t_data *data, char *filename);


#endif