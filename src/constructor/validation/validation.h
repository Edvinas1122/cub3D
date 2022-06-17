#ifndef CUBE3D_CONSTRUCTOR_VALIDATION_H
# define CUBE3D_CONSTRUCTOR_VALIDATION_H

# include "../constructor.h"

typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_texture	t_texture;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;
typedef struct	s_door		t_door;
/*
	Temporary data, relarted to a validation process
*/
typedef struct	s_map_c
{
	t_list	**file;
	char	**map;
	t_door	**doormap;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling;
	char	*floor;

}	t_map_c;

int	validate_cub_file(t_list **file, t_map_c *tmp);

/*
	validate_cub_file members
*/
int	validate_map(char **map);
int	validate_texture_names(t_list **file, t_map_c *tmp);

/*
	validate_map members
*/
int	matrix_neighbour_check(char **map, char *victims);

int check_leaping_column_uncloses(char **map, char *valid_char);
int	check_bottom_row(char **map, char *valid_char);
int	all_rows_closed(char **map);

#endif