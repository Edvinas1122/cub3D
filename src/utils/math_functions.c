#include "utils.h"

/*
	Rotates vector by a given angle
*/
void	rotate_vector(t_vect *vector, double angle)
{
	double	tmpx = vector->x;
	double	tmpy = vector->y;

	vector->x = cos(angle * M_PI/180) * tmpx - sin(angle * M_PI/180) * tmpy;
	vector->y = sin(angle * M_PI/180) * tmpx + cos(angle * M_PI/180) * tmpy;
}

/*
	Returns vector lenght
*/
double	vector_length(t_vect *vector)
{
	return (sqrt(vector->x*vector->x + vector->y*vector->y));
}

double	point_distance(t_vect *v1, t_vect *v2)
{
	double x = v1->x - v2->x;
	double y = v1->y - v2->y;
	return (sqrt(x*x+y*y));
}

/*
	Normalize vector
*/
void	normalize_vector(t_vect *vector)
{
	double len;
	
	len = sqrt((vector->x * vector->x) + (vector->y * vector->y));
	if (len > 0)
	{
		vector->x /= len;
		vector->y /= len;
	}
}
