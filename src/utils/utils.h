#ifndef CUBE3D_UTILS_H
# define CUBE3D_UTILS_H

# include "../cube3d.h"

typedef struct	s_vect		t_vect;
typedef	struct	s_color		t_color;
typedef struct	s_data		t_data;
typedef struct	s_map		t_map;
typedef struct	s_texture	t_texture;
typedef struct	s_video		t_video;
typedef struct	s_mlx		t_mlx;


/*
	String functions
*/
void	compare_to_str(char c, char *valid_char);
int		compare_to_str2(char c, char *valid_char);
t_vect	find_char_cordinates(char **map, char *c);
char	*find_char(char **map, char *c);
int		*line_lenghts(char **map);

/*
	List functions
*/
char	**list_to_array_offset(t_list *lst, int i);
void	delete_list_node(void *lst);

/*
	Parce functios
*/
int		file_to_heap(char *name, t_list ***file);

/*
	Graphics
*/
t_color	string_to_color(char *str);
t_color	set_color(int a, int r, int g, int b);
t_color	dim_color(t_color color, double factor);
t_color	***create_pixel_matrix(char *img_data, int width, int height);
void	color_the_matrix(t_color ***img_matrix, int r, int g, int b);
t_texture	open_texture_xpm2(t_data *data, char *filename);

// t_color	set_color_fstr(void *bin);
void	pixel_put(t_color ***img_matrix, t_color color, int x, int y);

/*
	Math functions
*/
void	rotate_vector(t_vect *vector, double angle);
double	vector_length(t_vect *vector);
double	point_distance(t_vect v1, t_vect v2);
void	normalize_vector(t_vect *vector);
void	normalize_vector_t(t_vect *vector);
double	get_angle(t_vect *vector1, t_vect *vector2);
double	find_angle_vecotrs(t_vect vect1, t_vect vect2);
/*
	Game mechanics
*/
int			check_if_wall(t_data *data, t_vect point);
int			check_if_solid(t_data *data, t_vect point);
int			check_if_solid_around(t_data *data, t_vect point);
int			check_door(t_data *data, t_vect point, int direction);
long long	set_time(void);
#endif
