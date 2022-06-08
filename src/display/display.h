#ifndef CUBE3D_DISPLAY_H
# define CUBE3D_DISPLAY_H

# include "../cube3d.h"

typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_textures	t_textures;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;

int	render_display(t_data *data);

#endif