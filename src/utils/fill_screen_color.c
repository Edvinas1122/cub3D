/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:05 by emomkus           #+#    #+#             */
/*   Updated: 2022/06/20 23:06:06 by emomkus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
	To fill matrix with color
*/
void	color_the_matrix(t_color ***img_matrix, int r, int g, int b)
{
	int		row;
	int		col;

	row = 0;
	while (row < SCREEN_HEIGHT)
	{
		col = 0;
		while (col < SCREEN_WIDTH)
		{
			(img_matrix)[row][col]->a = (char)250;
			(img_matrix)[row][col]->r = (char)r;
			(img_matrix)[row][col]->g = (char)g;
			(img_matrix)[row][col]->b = (char)b;
			col++;
		}
		row++;
	}
}
