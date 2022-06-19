#include "validation.h"

t_door	*get_doormap_line(char *map, t_door **doors, int *doorcount)
{
	int		max_y;
	int		i;
	t_door	*doormap_line;

	max_y = 0;
	while (map[max_y])
		max_y++;
	doormap_line = ft_calloc(sizeof(t_door), max_y + 1);
	i = 0;
	while (i < max_y)
	{
		if (map[i] == '2')
		{
			doormap_line[i].solid = 1;
			doormap_line[i].moving = 0;
			doormap_line[i].closed_percentage = 100;
			doors[*doorcount] = &doormap_line[i];
			(*doorcount)++;
		}
		i++;
	}
	return (doormap_line);
}

t_door	**get_doormap(char	**map, t_door **doors)
{
	int		max_x;
	int		i;
	t_door	**doormap;
	int		doorcount;

	doorcount = 0;
	max_x = 0;
	while (map[max_x])
		max_x++;
	doormap = ft_calloc(sizeof(t_door *), max_x + 1);
	i = 0;
	while (i < max_x)
	{
		doormap[i] = get_doormap_line(map[i], doors, &doorcount);
		i++;
	}
	return (doormap);
}
