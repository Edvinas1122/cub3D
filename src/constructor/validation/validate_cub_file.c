#include "validation.h"

static int	color_conditions(char *number, int *ct, int *i, int *comma)
{
	if (ft_isdigit(number[*i]))
		*ct = *ct + 1;
	else if (ft_strncmp(&number[*i], ",", 1) && number[*i] != '\0')
		return (0);
	else
	{
		*comma = *comma + 1;
		if (*ct > 3)
			return (0);
		if (ft_atoi(&number[*i - *ct]) > 255)
			return (0);
		*ct = 0;
	}
	*i = *i + 1;
	return (1);
}

/*
	Alert ! DANGEROUS!
*/
static int	validate_color_numbers(char	*number)
{
	int	i;
	int	ct;
	int	comma;

	i = 0;
	ct = 0;
	comma = 0;
	if (ft_strlen(number) < 5)
		return (0);
	while (number[i - 1])
	{
		if (!color_conditions(number, &ct, &i, &comma))
			return (0);
	}
	if (comma != 3)
		return (0);
	return (1);
}

static int	validate_colors(t_list **file, t_map_c *tmp)
{
	t_list	*node;

	node = (*file)->next->next->next->next->next;
	if (ft_strncmp(node->content, "F ", 2))
		return (0);
	tmp->floor = &(node->content)[2];
	if (!validate_color_numbers(tmp->floor))
		return (0);
	node = node->next;
	if (ft_strncmp(node->content, "C ", 2))
		return (0);
	tmp->ceiling = &(node->content)[2];
	if (!validate_color_numbers(tmp->ceiling))
		return (0);
	node = node->next;
	if (ft_strncmp(node->content, "\0\0", 2))
		return (0);
	return (1);
}

int	count_doors(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
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
	if (!validate_map(tmp->map))
		return (0);
	tmp->doors = ft_calloc(sizeof(t_door *), count_doors(tmp->map) + 1);
	tmp->doormap = get_doormap(tmp->map, tmp->doors);
	return (1);
}
