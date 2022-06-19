#include "utils.h"

void	delocate_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	delocate_door(t_door **door)
{
	int	i;

	i = 0;
	while (door[i])
	{
		free(door[i]);
		i++;
	}
	free(door);
}
