/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:05:36 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:17:28 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MECHANICS_H
# define MECHANICS_H

# include "../../cub3d.h"

typedef struct s_wall		t_wall;
typedef struct s_intersect	t_intersect;
typedef struct s_raycast	t_raycast;
typedef struct s_vect		t_vect;
typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_video		t_video;
typedef struct s_mlx		t_mlx;

void	set_movement_vector(t_data *data);
void	unset_movement_vector(t_data *data);
void	trigger_area(t_data *data);
#endif