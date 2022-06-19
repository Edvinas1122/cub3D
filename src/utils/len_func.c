#include "utils.h"

/* 
	Returns a pointer to an integer array
	array represents LENGHTS of char array lines
*/
int	*line_lentghs(char **map)
{
	int	*arr;
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (map[i])
		i++;
	arr = ft_calloc(i + 1, sizeof(int));
	i = 0;
	while (map[i])
	{
		arr[i] = ft_strlen(map[i]);
		i++;
	}
	return (arr);
}
