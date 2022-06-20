/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture_names.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:12:16 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:12:59 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static int	texture_name_ends(t_map_c *tmp)
{
	int	len;

	len = ft_strlen(tmp->so);
	if (len < 5 || ft_strncmp(&tmp->so[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->no);
	if (len < 5 || ft_strncmp(&tmp->no[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->ea);
	if (len < 5 || ft_strncmp(&tmp->ea[len - 4], ".xpm\0", 5))
		return (0);
	len = ft_strlen(tmp->we);
	if (len < 5 || ft_strncmp(&tmp->we[len - 4], ".xpm\0", 5))
		return (0);
	return (1);
}

static int	check_for_zeros(char *check_arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (check_arr[i] == 0)
			return (0);
		i++;
	}
	return (1);
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
		if (value == -1 || check_arr[value] == 1)
			return (0);
		if (value != 6)
			check_arr[value] = 1;
		node = node->next;
		i++;
	}
	return (check_for_zeros(check_arr));
}

int	validate_info(t_list **file, t_map_c *tmp)
{
	if (!texture_name_begins(file, tmp))
		return (0);
	if (!texture_name_ends(tmp))
		return (0);
	return (1);
}
