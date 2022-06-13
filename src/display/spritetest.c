#include "display.h"


static t_sprite	init_test_sprite(t_color color, double x, double y)
{
	t_sprite sprite;
	sprite.position.x = x;
	sprite.position.y = y;
	sprite.size = 32;
	sprite.img_matrix = ft_calloc(sizeof(t_color **), sprite.size + 1);
	for (int i = 0; i < sprite.size; i++)
	{
		sprite.img_matrix[i] = ft_calloc(sizeof(t_color *), sprite.size + 1);
		for (int j = 0; j < sprite.size; j++)
		{
			sprite.img_matrix[i][j] = ft_calloc(sizeof(t_color), 1);
			sprite.img_matrix[i][j]->a = color.a;
			sprite.img_matrix[i][j]->r = color.r;
			sprite.img_matrix[i][j]->g = color.g;
			sprite.img_matrix[i][j]->b = color.b;
		}
	}
	return (sprite);
}

void	free_img_matrix(t_sprite *sprite)
{
	int i, j;

	i = 0;
	while (sprite->img_matrix[i])
	{
		j = 0;
		while (sprite->img_matrix[j])
		{
			free(sprite->img_matrix[i][j]);
			j++;
		}
		free(sprite->img_matrix[i][j]);
		free(sprite->img_matrix[i]);
		i++;
	}
	free(sprite->img_matrix[i]);
	free(sprite->img_matrix);
}

void *next_highest(t_sprite sprites[5], double *last_distance)
{
	double		tmpdist;
	void	*ptr;
	tmpdist = -1.0;
	for (int i = 0; i < 5; i++)
	{
		if (sprites[i].distance > tmpdist && sprites[i].distance < *last_distance)
		{
			ptr = &sprites[i];
			tmpdist = sprites[i].distance;
		}
	}
	*last_distance = tmpdist;
	return (ptr);
}

void	sprite_test(t_data *data)
{
	t_sprite	sprites[5];
	t_sprite	**spriteptr;
	double		tmpdbl;
	double planeX = 0.0, planeY = 0.66;
	//preparing the testsprites
	spriteptr = ft_calloc(sizeof(t_sprite *), 5);
	// printf("%f %f\n", data->player.pos.x, data->player.pos.y);
	sprites[0] = init_test_sprite(set_color(0, 255, 0, 0), 230.0, 410.0);
	sprites[1] = init_test_sprite(set_color(0, 0, 255, 0), 350, 310);
	sprites[2] = init_test_sprite(set_color(0, 0, 0, 255), 700, 110);
	sprites[3] = init_test_sprite(set_color(0, 255, 255, 0), 225, 810);
	sprites[4] = init_test_sprite(set_color(0, 255, 0, 255), 563, 213);
	
	//calculating the distance to each sprite
	for(int i=0; i < 5; i++)
		sprites[i].distance = point_distance(data->player.pos, sprites[i].position);
	
	//sorting the sprites by distance
	tmpdbl = 1000000;
	for(int i=0; i < 5; i++)
		spriteptr[i] = (t_sprite *)next_highest(sprites, &tmpdbl);

	// printf("-----------------------\n");
	// for(int i=0; i < 5; i++)
	// 	printf("%f\n", (*spriteptr[i]).distance);
	// printf("-----------------------\n");
	for(int i=0; i < 5; i++)
		free_img_matrix(&sprites[i]);
}