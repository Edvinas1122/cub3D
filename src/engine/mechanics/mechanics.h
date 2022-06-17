#ifndef CUBE3D_MECHANICS
# define CUBE3D_MECHANICS

#include "../../cube3d.h"

typedef struct	s_wall		t_wall;
typedef struct	s_intersect	t_intersect;
typedef struct	s_raycast	t_raycast;
typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_texture	t_texture;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;

void	set_movement_vector(t_data *data);
void	unset_movement_vector(t_data *data);
#endif