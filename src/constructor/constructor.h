/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:03:09 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:17:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCTOR_H
# define CONSTRUCTOR_H

# include "../cub3d.h"
# include "validation/validation.h"

typedef struct s_vect		t_vect;
typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_video		t_video;
typedef struct s_mlx		t_mlx;
typedef struct s_utils		t_utils;

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
t_utils		set_utils(t_data *data);
void		set_sprites(t_data *data, char *sprite_ini);
t_texture	open_texture_xpm(t_data *data, char *filename);
t_list		**open_sprite_ini(t_texture **sprites, char *sprite_ini);
t_color		***create_color_matrix(int width, int height, t_tmp_video *img);

/*
	member of set sprites
*/
void		set_minimap_frame(t_data *data);
char		*set_soundtrack(t_list **file);
void		set_bigmap_background(t_data *data);

/*
	member of destructor
*/
void		delocate_sprite_animation(t_data *data);
void		delocate_texture_array(t_data *data, t_texture *arr);
void		destroy_mtrx_video(t_data *data, t_video texture);
void		destroy_mtrx_image(t_data *data, t_texture texture);

#endif