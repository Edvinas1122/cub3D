#include "utils.h"

/*
	Find angle between player direction and sprite
*/
double	find_angle_vecotrs(t_vect vect1, t_vect vect2)
{
	double	angle;


	angle = atan2(vect1.y, vect1.x) - atan2(vect2.y, vect2.x);
	if (angle > M_PI)
		angle -= 2*M_PI;
	else if (angle < -M_PI)
		angle += 2*M_PI;
	return (angle);
}