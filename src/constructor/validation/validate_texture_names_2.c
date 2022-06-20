/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_names_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:12:13 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:12:14 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

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

int	check_for_textures(t_list *node, t_map_c *tmp)
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
	return (-1);
}

int	check_for_convention(t_list *node, t_map_c *tmp)
{
	int	ret;

	ret = check_for_textures(node, tmp);
	if (ret != -1)
		return (ret);
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

int	figure_out_map_begin(t_list **file)
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
