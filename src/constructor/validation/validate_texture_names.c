#include "validation.h"

static int	texture_name_ends(t_map_c *tmp)
{
	int	len;

	len = ft_strlen(tmp->ea);
	if (len < 5 || ft_strncmp(&tmp->ea[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->no);
	if (len < 5 || ft_strncmp(&tmp->no[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->no);
	if (len < 5 || ft_strncmp(&tmp->ea[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->we);
	if (len < 5 || ft_strncmp(&tmp->we[len - 4], ".xpm\0", 5))
		return (0);
	return (1);
}

static int	texture_name_begins(t_list **file, t_map_c *tmp)
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

int	validate_texture_names(t_list **file, t_map_c *tmp)
{
	if (!texture_name_begins(file, tmp))
		return (0);
	if (!texture_name_ends(tmp))
		return (0);
	return (1);
}
