/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:28 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:17:09 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "../cub3d.h"

typedef struct s_vect		t_vect;
typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_textures	t_textures;
typedef struct s_video		t_video;
typedef struct s_mlx		t_mlx;

int		player_action(int keycode, t_data *data);
int		red_x_win(t_data *data);
int		player_mouse_action(int x, int y, t_data *data);
int		player_mouse_action_stop(int x, int y, t_data *data);
int		player_stop_movement(int keycode, t_data *data);

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
void	rotate_player(t_data *data, int x);

/*
	More
*/
void	pop_minimap(t_data *data);
void	close_win(t_data *data);
void	menu_pop(t_data *data);
void	toggle_door(t_data *data);

#endif