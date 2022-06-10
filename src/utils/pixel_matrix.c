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
