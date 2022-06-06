#ifndef CUBE3D_UTILS_H
# define CUBE3D_UTILS_H

# include "../cube3d.h"

char	**list_to_array_offset(t_list *lst, int i)
void	compare_to_str(char c, char *valid_char);
void	compare_to_str2(char c, char *valid_char);
int		*line_lenghts(char **map);
t_color	string_to_color(char *str);
t_vect	find_char_cordinates(char **map, char *c);
char	*find_char(char **map, char *c);

#endif