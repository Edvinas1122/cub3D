#include "display.h"
void	draw_the_mother_fucking_sprite(t_data *data, t_sprite sprite);

/*
	initiating the sprites I'm using for testing
*/
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


/*
	freeing the sprite memory again - again just for testing
*/
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

/*
	finds the sprite with the next highest distance. 
	Meant to be initiated with very high last_distance
	and have it loop through number of sprites
	returns pointer to the sprite object
*/
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

/*
	calculates and returns the respective y value for an angle
*/
int	angle_to_column(double angle, t_vect dir)
{
	double	tmp;

	tmp = ((double)SCREEN_WIDTH * tan(angle))/2;
	return (SCREEN_WIDTH/2 + tmp);
}

/*
	The big one: does everything there is to be done for sprites
*/
void	sprite_test(t_data *data)
{
	t_sprite	sprites[5];
	t_sprite	**spriteptr;
	double		tmpdbl;
	t_vect	spritevect;

	//preparing the testsprites
	spriteptr = ft_calloc(sizeof(t_sprite *), 5);
	sprites[0] = init_test_sprite(set_color(0, 255, 0, 0), 230.0, 410.0);
	sprites[1] = init_test_sprite(set_color(0, 0, 255, 0), 350, 310);
	sprites[2] = init_test_sprite(set_color(0, 0, 0, 255), 700, 110);
	sprites[3] = init_test_sprite(set_color(0, 255, 255, 0), 225, 810);
	sprites[4] = init_test_sprite(set_color(0, 255, 0, 255), 563, 213);
	
	/*
		UP UNTIL THIS POINT, EVERYTHING SHOULD HAVE HAPPENED IN THE CONSTRUCTOR OF THE PROGRAM
	*/
	/*
		EVERYTHING BELOW NEEDS TO BE DONE AFTER RENDERING THE WALLS
		anytime it counts up to 5, we will need to iterate through all sprites
	*/

	/*
		calculating the distance to each sprite
	*/
	for(int i=0; i < 5; i++){
		spritevect.x = sprites[i].position.x - data->player.pos.x;
		spritevect.y = sprites[i].position.y - data->player.pos.y;
		normalize_vector(&spritevect);
		sprites[i].distance = point_distance(data->player.pos, sprites[i].position);
	}
	/*
		sorting the sprites by distance
	*/
	tmpdbl = 2e30;
	for(int i=0; i < 5; i++)
		spriteptr[i] = (t_sprite *)next_highest(sprites, &tmpdbl);


	//draw each sprite
	for(int i = 0; i < 5; i++)
	{
		//find sprite direction vector
		spritevect.x = (*spriteptr[i]).position.x - data->player.pos.x;
		spritevect.y = (*spriteptr[i]).position.y - data->player.pos.y;
		normalize_vector(&spritevect);

		//find angle between player direction and sprite
		double angle;
		angle = atan2(spritevect.y, spritevect.x) - atan2(data->player.vect.y, data->player.vect.x);
		if (angle > M_PI)
			angle -= 2*M_PI;
		else if (angle < -M_PI)
			angle += 2*M_PI;

		//find x position of sprite
		(*spriteptr[i]).on_screen.x = angle_to_column(angle, data->player.vect);
		//find y position of sprite
		(*spriteptr[i]).distance /= 1/(cos(get_angle(&data->player.vect, &spritevect) / (180/M_PI)));
		(*spriteptr[i]).on_screen.y = (double)TILE_SIZE/(*spriteptr[i]).distance;
		(*spriteptr[i]).on_screen.y = SCREEN_HEIGHT/2 + (SCREEN_HEIGHT/2 * (*spriteptr[i]).on_screen.y);

		/*
			NOTE: spritex_on_screen/spritey_on_screen is the position of the BOTTOM CENTER point of the sprite
			example: if this is a sprite, the point will be the X
					00000
					00000
					00000
					00000
					00X00
		*/

		//draw the motherfucking sprite
		//sprites currently aren't drawn if more than half of them would be offscreen to the side
		if ((*spriteptr[i]).on_screen.x >= 0 && (*spriteptr[i]).on_screen.x < SCREEN_WIDTH && (angle*180/M_PI) > -90 && (angle*180/M_PI) < 90)
			draw_the_mother_fucking_sprite(data, (*spriteptr[i]));
	}
	for(int i=0; i < 5; i++)
		free_img_matrix(&sprites[i]);
}

void	draw_the_mother_fucking_sprite(t_data *data, t_sprite sprite)
{
	double	scalefactor;
	int		scaledsize;
	int		xstart;
	int		ystart;

	scalefactor = 1 / (sprite.distance / TILE_SIZE);
	scaledsize = (int)(sprite.size * scalefactor);
	xstart = (int)sprite.on_screen.x - scaledsize/2;
	ystart = (int)sprite.on_screen.y - scaledsize;
	for (int x = 0; x < scaledsize; x++)
	{
		if  (xstart + x >= 0 && xstart + x < SCREEN_WIDTH && data->map.z_buffer[xstart + x] > sprite.distance) //checking if wall at this column is closer, and if it's offscreen
		{
			for (int j = 0; j < scaledsize; j++)
				if (ystart + j >= 0 &&ystart + j < SCREEN_HEIGHT)	//checking if y val is offscreen
					pixel_put(data->video.img_matrix, *sprite.img_matrix[0][0], xstart + x, ystart + j);
		}
	}
}