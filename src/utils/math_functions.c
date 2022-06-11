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

/*
	Returns the angle (in degrees) between two vectors
*/
double	get_angle(t_vect *vector1, t_vect *vector2)
{
	t_vect	tmp1;
	t_vect	tmp2;
	double	angle;

	tmp1.x = vector1->x;
	tmp2.x = vector2->x;
	tmp1.y = vector1->y;
	tmp2.y = vector2->y;
	normalize_vector(&tmp1);
	normalize_vector(&tmp2);
	angle = acos(tmp1.x * tmp2.x + tmp1.y * tmp2.y) * (180/M_PI);
	return (angle);
}