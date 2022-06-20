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

int	until_not_space(char *ptr)
{
	int	i;

	i = 0;

	while (ptr[i] != ' ')
		i++;
	while (ptr[i] == ' ')
		i++;
	return (i);
}

static int	check_for_convention(t_list *node, t_map_c *tmp)
{

	if (!ft_strncmp(node->content, "NO ", 3))
	{
		tmp->no = &(node->content)[until_not_space(node->content)];
		return (0);
	}
	if (!ft_strncmp(node->content, "SO ", 3))
	{
		tmp->so = &(node->content)[until_not_space(node->content)];
		return (1);
	}
	if (!ft_strncmp(node->content, "WE ", 3))
	{
		tmp->we = &(node->content)[until_not_space(node->content)];
		return (2);
	}
	if (!ft_strncmp(node->content, "EA ", 3))
	{
		tmp->ea = &(node->content)[until_not_space(node->content)];
		return (3);
	}
	if (!ft_strncmp(node->content, "F ", 2))
	{
		tmp->floor = &(node->content)[until_not_space(node->content)];
		return (4);
	}
	if (!ft_strncmp(node->content, "C ", 2))
	{
		tmp->ceiling = &(node->content)[until_not_space(node->content)];
		return (5);
	}
	if (!ft_strncmp(node->content, "\0\0", 2))
		return (6);
	return (-1);
}

static int	figure_out_map_begin(t_list **file)
{
	int		i;
	t_list	*node;

	node = *file;
	i = 0;
	while (node && !(!ft_strncmp(node->content, "1", 1)
			|| !ft_strncmp(node->content, " ", 1)))
	{
		node = node->next;
		i++;
	}
	return (i);
}

static int	texture_name_begins(t_list **file, t_map_c *tmp)
{
	t_list	*node;
	int		i;
	int		size;
	char	check_arr[7];
	int		value;

	i = 0;
	size = figure_out_map_begin(file);
	ft_bzero(check_arr, 7);
	node = *file;
	while (i < size)
	{
		value = check_for_convention(node, tmp);
		if (value == -1)
			return (0);
		if (value != 6)
			check_arr[value] = 1;
		node = node->next;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (check_arr[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	validate_info(t_list **file, t_map_c *tmp)
{
	if (!texture_name_begins(file, tmp))
		return (0);
	if (!texture_name_ends(tmp))
		return (0);
	return (1);
}
