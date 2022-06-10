#ifndef CUBE3D_CONTROL_H
# define CUBE3D_CONTROL_H

# include "../cube3d.h"

typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_textures	t_textures;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;

int		player_action(int keycode, t_data *data);

/*
	Move player functions
*/
void	move_forward(t_data *data);
void	move_backwards(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/*
	Rotate player
*/
void	rotate_player_left(t_data *data);
void	rotate_player_right(t_data *data);

#endif