#include "constructor.h"

/* 
	Checks for file format in a file name 
*/
static void	validate_file_name(char *name)
{
	if (ft_strlen(name) < 4)
		exit(0);
		//error_terminate(6, NULL, NULL);
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".cub", 4))
		exit(0);
		//error_terminate(6, NULL, NULL);
}

static t_map	assign_map(t_map_c tmp)
{
	t_map	map;

	map.bit_map = tmp.map;
	map.ceiling = string_to_color(tmp.ceiling);
	map.floor = string_to_color(tmp.floor);
	//map.textur = open_textures_xmp(tmp_file);
	return (map);
}

/* 
	Opens .cub file 
	Returns t_map struct
*/
t_map	open_cub_file(char *name)
{
	t_map	map;
	t_map_c tmp;

	validate_file_name(name);
	tmp.file = file_to_heap(name);
	tmp = validate_file(tmp.file);
	map = assign_map(tmp);
	return (map);
}