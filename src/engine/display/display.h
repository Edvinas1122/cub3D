#ifndef DISPLAY_H
# define DISPLAY_H

# include "../../cube3d.h"

typedef struct s_wall			t_wall;
typedef struct s_intersect		t_intersect;
typedef struct s_raycast		t_raycast;
typedef struct s_vect			t_vect;
typedef struct s_color			t_color;
typedef struct s_data			t_data;
typedef struct s_map			t_map;
typedef struct s_texture		t_texture;
typedef struct s_video			t_video;
typedef struct s_mlx			t_mlx;
typedef struct s_draw_sprite	t_draw_sprite;
typedef struct s_utils			t_utils;

typedef struct s_draw_ent
{
	double	sf;
	int		scaledwidth;
	int		scaledheight;
	int		xstart;
	int		ystart;
	double	distance;
	double	dim;
	t_color	color;
}	t_draw_entity;

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
	int		start;
	int		end;
	t_color	color;
	int		iterator;
	double	dim;
	int		txt_x;
	int		txt_y;
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

typedef struct s_hit
{
	double	tmpdist;
	int		hit_wall;
	int		hit_door;
	t_vect	tmp;
}	t_hit;

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
	int		cardinal_direction;
	int		isdoor;
}	t_raycast;

typedef struct s_dis_draw_spr
{
	double	scalefactor;
	int		scaledwidth;
	int		scaledheight;
	int		xstart;
	int		ystart;
}	t_dis_draw_spr;

/*
	Main function
*/
int			render_display(t_data *data);

/*
	Members of render_display
*/
void		render_fov_view(t_data *data);
void		display_minimap(t_data *data);
void		render_menu(t_data *data);
void		draw_2d_minimap_small(t_data *data, double sf);

/*
	Members of render fov view
*/
void		draw_vertical_line(t_data *data, t_raycast *raycast);
void		draw_wall_line(t_data *data, t_raycast *raycast, t_wall *wall);
t_vect		find_intersections(t_data *data, t_vect *dir, t_raycast *raycast);
void		draw_floor_and_ceiling(t_data *data);
void		sprite_draw(t_data *data);

/*
	Members of sprite draw
*/
void		draw_the_mother_ducking_sprite(t_data *data, \
					t_texture sprite_data, t_entity sprite);
void		calculate_draw(t_draw_sprite *layer, t_data *data);
t_texture	set_sprite_image(t_draw_sprite *layer, t_data *data, int i);
void		display_bigmap_background(t_texture bg, t_color ***img, double sf);
void		draw_big_map(t_data *data);
void	draw_player_big(t_data *data, t_vect pos);
#endif
