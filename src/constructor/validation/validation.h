/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:12:19 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/21 12:31:07 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "../constructor.h"

typedef struct s_color		t_color;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_video		t_video;
typedef struct s_mlx		t_mlx;
typedef struct s_door		t_door;
/*
	Temporary data, related to a validation process
*/
typedef struct s_map_c
{
	t_list	**file;
	char	**map;
	t_door	**doormap;
	t_door	**doors;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling;
	char	*floor;

}	t_map_c;

int		validate_cub_file(t_list **file, t_map_c *tmp);

/*
	validate_cub_file members
*/
int		validate_map(char **map);
int		validate_info(t_list **file, t_map_c *tmp);

/*
	validate_map members
*/
int		matrix_neighbour_check(char **map, char *victims);
int		check_leaping_column_uncloses(char **map, char *valid_char);
int		check_bottom_row(char **map, char *valid_char);
int		all_rows_closed(char **map);
int		until_not_space(char *ptr);
int		check_for_textures(t_list *node, t_map_c *tmp);
int		check_for_convention(t_list *node, t_map_c *tmp);
int		figure_out_map_begin(t_list **file);

/*
	get door
*/
t_door	*get_doormap_line(char *map, t_door **doors, int *doorcount);
t_door	**get_doormap(char	**map, t_door **doors);

#endif
