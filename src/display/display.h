#ifndef CUBE3D_DISPLAY_H
# define CUBE3D_DISPLAY_H

#include "../cube3d.h"

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

int		render_display(t_data *data);
void	display_minimap(t_data *data);
void	render_fov_view(t_data *data);
void	draw_vertical_line(t_data *data, t_raycast *raycast);
void	draw_wall_line(t_data *data, t_raycast *raycast, t_wall *wall);
double	intersection_distances(t_vect pos, t_vect *dir, t_raycast *raycast);
void	draw_floor_and_ceiling(t_data *data);

#endif