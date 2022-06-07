#ifndef CUBE3D_UTILS_H
# define CUBE3D_UTILS_H

# include "../cube3d.h"

typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_textures	t_textures;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;

char	**list_to_array_offset(t_list *lst, int i);
void	compare_to_str(char c, char *valid_char);
int		compare_to_str2(char c, char *valid_char);
int		*line_lenghts(char **map);
t_color	string_to_color(char *str);
t_vect	find_char_cordinates(char **map, char *c);
char	*find_char(char **map, char *c);
t_list	**file_to_heap(char *name);

#endif