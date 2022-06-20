/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:04:11 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:04:12 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constructor.h"

/* 
	Checks for file format in a file name 
*/
static int	validate_file_name(char *name)
{
	if (ft_strlen(name) < 4)
	{
		ft_putstr_fd("Invalid .cub file name\n", 1);
		return (0);
	}
	if (ft_strncmp(&name[ft_strlen(name) - 4], ".cub", 4))
	{
		ft_putstr_fd("Invalid .cub file name\n", 1);
		return (0);
	}
	return (1);
}

static t_map	assign_map(t_data *data, t_map_c tmp)
{
	t_map	map;

	map.bit_map = tmp.map;
	map.doormap = tmp.doormap;
	map.ceiling = string_to_color(tmp.ceiling);
	map.floor = string_to_color(tmp.floor);
	map.north = load_texture_files(data, tmp.no);
	map.south = load_texture_files(data, tmp.so);
	map.east = load_texture_files(data, tmp.ea);
	map.west = load_texture_files(data, tmp.we);
	map.door = load_texture_files(data, "./assets/textures/zo_portail2.xpm");
	return (map);
}

/* 
	Opens .cub file 
	Sets in data->map the t_map struct data
*/
void	open_cub_file(char *file_name, t_data *data)
{
	t_map_c	tmp;

	if (!validate_file_name(file_name))
		destructor(data);
	if (!file_to_heap(file_name, &tmp.file))
	{
		ft_putstr_fd("File access error\n", 1);
		destructor(data);
	}
	if (!validate_cub_file(tmp.file, &tmp))
	{
		lst_clear_2(tmp.file);
		destructor(data);
	}
	data->map = assign_map(data, tmp);
	data->doors = tmp.doors;
	lst_clear_2(tmp.file);
}
