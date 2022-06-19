#include "utils.h"

/**
	Sets pixel in a given coordinate of a given color 
	@param color
	@param x 
	@param y
*/
void	pixel_put(t_color ***img_matrix, t_color color, int x, int y)
{
	*img_matrix[(int)y][(int)x] = color;
}

/*
	Links row to img_data row representing address
	Links row's members with img_data row's members
*/
static void	link_to_img_row(t_color **row, char *img_data, int width, int i)
{
	int	i2;
	int	offset;

	offset = width * i * 4;
	i2 = 0;
	while (i2 < width)
	{
		row[i2] = (t_color *)&img_data[offset + (i2 * 4)];
		i2++;
	}
}

/**
	@brief Create a 2D array or t_color that is dirrectly linked to img_data
	for array methods of accessing memory of an image -> pixels -> colors
*/
t_color	***create_pixel_matrix(char *img_data, int width, int height)
{
	t_color	***array;
	int		i;

	i = 0;
	array = ft_calloc(height + 1, sizeof(t_color **));
	while (height > i)
	{
		array[i] = ft_calloc(width + 1, sizeof(t_color *));
		link_to_img_row(array[i], img_data, width, i);
		i++;
	}
	return (array);
}
