#ifndef CUBE3D_CONSTRUCTOR_VALIDATION_H
# define CUBE3D_CONSTRUCTOR_VALIDATION_H

# include "../constructor.h"

/* Temporary data, relarted to a validation process */
typedef struct	s_map_c
{
	t_list	**file;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling;
	char	*floor;

}	t_map_c;

void	validate_cub_file(t_list **file);

/* validate_cub_file members */
t_map_c	validate_map(char **map);

/* validate_map members */
void	matrix_neighbour_check(char **map, char *victims);

#endif