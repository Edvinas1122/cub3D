#include "validation.h"

static void	validate_colors(t_list **file, t_map_c *tmp)
{
	t_list	*node;

	node = (*file)->next->next->next->next->next;
	if (ft_strncmp(node->content, "F ", 2))
		exit(0);
	tmp->floor = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "C ", 2))
		exit(0);
	tmp->ceiling = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "\0\0", 2))
		exit(0);
}

// Invalid delocation
static void	validate_texture_names(t_list **file, t_map_c *tmp)
{
	t_list	*node;

	node = *file;
	if (ft_strncmp(node->content, "NO ", 3))
		exit(0);
	tmp->no = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "SO ", 3))
		exit(0);
	tmp->so = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "WE ", 3))
		exit(0);
	tmp->we = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "EA ", 3))
		exit(0);
	tmp->ea = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "\0\0", 2))
		exit(0);
}

/* 
	Validates cub file for defined standart
	Returns temporary pointers for capturing
	specific variable values
*/
t_map_c	validate_cub_file(t_list **file)
{
	t_map_c	tmp;

	validate_texture_names(file, &tmp);
	printf("Texture names valid\n");
	validate_colors(file, &tmp);
	printf("Color names valid\n");
	tmp.map = list_to_array_offset(*file, 6);
	printf("Array of list is valid\n");
	validate_map(tmp.map);
	printf("Map valid\n");
	return(tmp);
}
