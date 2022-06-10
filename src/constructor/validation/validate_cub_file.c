#include "validation.h"

static int	validate_colors(t_list **file, t_map_c *tmp)
{
	t_list	*node;

	node = (*file)->next->next->next->next->next;
	if (ft_strncmp(node->content, "F ", 2))
		return (0);
	tmp->floor = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "C ", 2))
		return (0);
	tmp->ceiling = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "\0\0", 2))
		return (0);
	return (1);
}

// Invalid delocation
static int	validate_texture_names(t_list **file, t_map_c *tmp)
{
	t_list	*node;

	node = *file;
	if (ft_strncmp(node->content, "NO ", 3))
		return (0);
	tmp->no = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "SO ", 3))
		return (0);
	tmp->so = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "WE ", 3))
		return (0);
	tmp->we = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "EA ", 3))
		return (0);
	tmp->ea = &(node->content)[3];
	node = node->next;
	if (ft_strncmp(node->content, "\0\0", 2))
		return (0);
	return (1);
}

/* 
	Validates cub file for defined standart
	Returns temporary pointers for capturing
	specific variable values
*/
int	validate_cub_file(t_list **file, t_map_c *tmp)
{
	if (!validate_texture_names(file, tmp))
	{
		ft_putstr_fd("Invalid texture convention\n", 1);
		return (0);		
	}
	if (!validate_colors(file, tmp))
	{
		ft_putstr_fd("Invalid color convention\n", 1);
		return (0);
	}
	tmp->map = list_to_array_offset(*file, 8);
	validate_map(tmp->map);
	return (1);
}
