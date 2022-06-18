#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/time.h>
# include "cube3d_common.h"
# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"
# include "constructor/constructor.h"
# include "control/control.h"
# include "utils/utils.h"
# include "engine/display/display.h"
# include "engine/mechanics/mechanics.h"

# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 900
# define MOVE_DISTANCE 6
# define TILE_SIZE 100
# define FOV 90
# define MOUSE_SENSITIVITY 10

/*
	Additional info for future includes
*/
typedef struct s_utils
{
	t_color		minimap[4];
	t_sprite_data	*minimap_frame;
	int			minimap_size;
	char		*soundtrack;
	t_texture	pause;
	int			game_state;
	int			move_factor;
	long		time_stamp;
	long		old_time_stamp;
}	t_utils;


/*
	Player position in a world data
*/
typedef struct	s_player
{
	t_vect	pos;
	t_vect	vect;
	t_vect	movement;
	int		dash_cooldown;
}	t_player;

/*
	provides info if key is pressed
	or released
	and	info if it was read
*/
typedef struct	s_keypress
{
	char	key_w[2];
	char	key_s[2];
	char	key_a[2];
	char	key_d[2];
	char	key_space[2];
}	t_keypress;

/*
	Main data stack segment
*/
typedef struct	s_data
{
	t_map			map;
	t_player		player;
	t_mlx			mlx;
	t_video			video;
	t_utils			util;
	t_keypress		keys;
	t_door			**doors;
	int				count;
	t_sprite_data	*sprite_images;
	t_sprite_anim	*sprite_anim;
	t_sprite		*sprite_objects;
	t_sprite		**sprite_arr;
}	t_data;

typedef struct	s_draw_sprite
{
	t_sprite_data	*sprite_images;
	t_sprite		*objects;
	t_sprite		**sprite_arr;
	double			tmpdbl;
	t_vect			sprite_vect;
	int				obj_count;
}	t_draw_sprite;


int		main(int argc, char **argv);
int		engine(t_data *data);
void	player_movement(t_data *data);
void	play_audio(char *audio);
void	end_audio(void);

#endif
