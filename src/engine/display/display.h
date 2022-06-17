#ifndef CUBE3D_DISPLAY_H
# define CUBE3D_DISPLAY_H

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

typedef struct s_line
{
	t_texture	texture;
	double		strech_factor;
	int			horizontal_offset;
	int			vertical_offset;
}	t_line;

/**
 @param ray_dir vector of current cast direction
 @param target	e
 @param impact	position where ray hits a wall
 @param v_line_ct count of which vertical line we refer
*/
typedef struct s_wall
{
	double	y;
	double	size;
	int		offset;
	int		start;
	int		end;
	t_color color;
}	t_wall;

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
	int		isdoor;
}	t_raycast;

int		render_display(t_data *data);
void	display_minimap(t_data *data);
void	render_menu(t_data *data);
void	render_fov_view(t_data *data);
void	draw_vertical_line(t_data *data, t_raycast *raycast);
void	draw_wall_line(t_data *data, t_raycast *raycast, t_wall *wall);
double	intersection_distances(t_vect pos, t_vect *dir, t_raycast *raycast, int doorflag);
void	draw_floor_and_ceiling(t_data *data);
void	sprite_test(t_data *data);

#endif