#include "display.h"


static t_sprite	init_test_sprite(t_color color, double x, double y)
{
	t_sprite sprite;
	sprite.position.x = x;
	sprite.position.y = y;
	sprite.size = 300;
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
		// printf("trying to find a distance that is higher than %f but lower than %f\n", tmpdist, *last_distance);
		if (sprites[i].distance > tmpdist && sprites[i].distance < *last_distance)
		{
			ptr = &sprites[i];
			tmpdist = sprites[i].distance;
		}
	}
	// printf("%f IS THE HIGHEST!!!\n", tmpdist);
	*last_distance = tmpdist;
	return (ptr);
}

int	angle_to_column(double angle, t_vect dir)
{
	double	tmp;

	tmp = ((double)SCREEN_WIDTH * tan(angle))/2;
	return (SCREEN_WIDTH/2 + tmp);
}

void	sprite_test(t_data *data)
{
	t_sprite	sprites[5];
	t_sprite	**spriteptr;
	double		tmpdbl;
	t_vect	spritevect;

	//preparing the testsprites
	spriteptr = ft_calloc(sizeof(t_sprite *), 5);
	// printf("%f %f\n", data->player.pos.x, data->player.pos.y);
	sprites[0] = init_test_sprite(set_color(0, 255, 0, 0), 230.0, 410.0);
	sprites[1] = init_test_sprite(set_color(0, 0, 255, 0), 350, 310);
	sprites[2] = init_test_sprite(set_color(0, 0, 0, 255), 700, 110);
	sprites[3] = init_test_sprite(set_color(0, 255, 255, 0), 225, 810);
	sprites[4] = init_test_sprite(set_color(0, 255, 0, 255), 563, 213);
	
	//calculating the distance to each sprite
	for(int i=0; i < 5; i++){
		spritevect.x = sprites[i].position.x - data->player.pos.x;
		spritevect.y = sprites[i].position.y - data->player.pos.y;
		normalize_vector(&spritevect);
		sprites[i].distance = point_distance(data->player.pos, sprites[i].position);
	}
	//sorting the sprites by distance
	tmpdbl = 1000000;
	for(int i=0; i < 5; i++)
		spriteptr[i] = (t_sprite *)next_highest(sprites, &tmpdbl);

	// for(int i=0; i < 5; i++)
	// 	printf("DISTANCE pos %d: %f\n", i, (*spriteptr[i]).distance);

	// printf("%f %f\n", data->player.vect.x,data->player.vect.y);
	//find angle between player vector and sprite angle
	//dear future me: have fun with this dogshit lmao
	for(int i=0; i < 5; i++)
	{
		// printf("%f\n", (*spriteptr[i]).distance);
		spritevect.x = (*spriteptr[i]).position.x - data->player.pos.x;
		spritevect.y = (*spriteptr[i]).position.y - data->player.pos.y;
		normalize_vector(&spritevect);
		double angle2;
		angle2 = atan2(spritevect.y, spritevect.x) - atan2(data->player.vect.y, data->player.vect.x);
		if (angle2 > M_PI)
			angle2 -= 2*M_PI;
		else if (angle2 < -M_PI)
			angle2 += 2*M_PI;
		double tmpcolumn = angle_to_column(angle2, data->player.vect);
		// printf("angle: %f\n", angle2*180/M_PI);
		t_color tmpcolor;
		tmpcolor.a = 0;
		tmpcolor.r = 255;
		tmpcolor.g = 0;
		tmpcolor.b = 0;
		double anothertest;
		(*spriteptr[i]).distance /= 1/(cos(get_angle(&data->player.vect, &spritevect) / (180/M_PI)));
		anothertest = (double)TILE_SIZE/(*spriteptr[i]).distance;
		anothertest = SCREEN_HEIGHT/2 + (SCREEN_HEIGHT/2 * anothertest);
		// printf("%f\n", anothertest);
		int	xstart = tmpcolumn - 7;
		int	ystart = (int)anothertest - 7;
		if (tmpcolumn >= 0 && tmpcolumn < SCREEN_WIDTH && (angle2*180/M_PI) > -90 && (angle2*180/M_PI) < 90)
		{
			double	apparentsize;
			int		intsize;
			apparentsize = (*spriteptr[i]).size / ((*spriteptr[i]).distance / TILE_SIZE);
			intsize = (int)apparentsize;
			int xstart = tmpcolumn - intsize/2;
			int ystart = (int)anothertest - intsize;
			for (int x = 0; x < intsize; x++)
			{
				// printf("%f vs %f\n", data->map.z_buffer[xstart + x] , (*spriteptr[i]).distance);
				if  (xstart + x >= 0 && xstart + x < SCREEN_WIDTH && data->map.z_buffer[xstart + x] > (*spriteptr[i]).distance)
				{
					for (int j = 0; j < intsize; j++)
						if (ystart + j >= 0 &&ystart + j < SCREEN_HEIGHT)
							pixel_put(data->video.img_matrix, *(*spriteptr[i]).img_matrix[0][0], xstart + x, ystart + j);
				}
				// printf("%d\n")
			}
			// for (int i = 0;i<15;i++)
			// {
			// 	if (xstart + i > 0 && ystart + i > 0 && xstart + i < SCREEN_WIDTH && ystart + i < SCREEN_HEIGHT)
			// 		pixel_put(data->video.img_matrix, tmpcolor, xstart + i, ystart + i);
			// 	if (xstart + 15 - i > 0 && ystart + i > 0 && xstart + 15 - i < SCREEN_WIDTH && ystart + i < SCREEN_HEIGHT)
			// 		pixel_put(data->video.img_matrix, tmpcolor, xstart + 15 - i, ystart + i);
			// }
		}
			// for (int i=0; i<SCREEN_HEIGHT; i++)
			// 		pixel_put(data->video.img_matrix, tmpcolor, tmpcolumn, i);

	}
	// printf("----------------------------------\n");


	// printf("-----------------------\n");
	// for(int i=0; i < 5; i++)
	// 	printf("%f\n", (*spriteptr[i]).distance);
	// printf("-----------------------\n");
	for(int i=0; i < 5; i++)
		free_img_matrix(&sprites[i]);
}