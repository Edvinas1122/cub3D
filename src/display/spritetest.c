#include "display.h"
void	draw_the_mother_fucking_sprite(t_data *data, t_sprite_data sprite_data, t_sprite sprite);


static	t_sprite_data	init_test_sprite_data(t_color color)
{
	t_sprite_data sprite_data;

	sprite_data.width = 64;
	sprite_data.height = 64;
	sprite_data.img_matrix = ft_calloc(sizeof(t_color **), sprite_data.width + 1);
	for (int i = 0; i < sprite_data.width; i++)
	{
		sprite_data.img_matrix[i] = ft_calloc(sizeof(t_color *), sprite_data.height + 1);
		for (int j = 0; j < sprite_data.height; j++)
		{
			sprite_data.img_matrix[i][j] = ft_calloc(sizeof(t_color), 1);
			sprite_data.img_matrix[i][j]->a = color.a;
			sprite_data.img_matrix[i][j]->r = color.r - (int)(j * ((double)color.r/sprite_data.height))- (int)(i * ((double)color.r/sprite_data.width));
			sprite_data.img_matrix[i][j]->g = color.g - (int)(j * ((double)color.g/sprite_data.height))- (int)(i * ((double)color.g/sprite_data.width));
			sprite_data.img_matrix[i][j]->b = color.b - (int)(j * ((double)color.b/sprite_data.height))- (int)(i * ((double)color.b/sprite_data.width));
		}
	}
	sprite_data.img_matrix[0][0]->a = 255;
	sprite_data.img_matrix[8][8]->a = 255;
	return (sprite_data);
}
/*
	initiating the sprites I'm using for testing
*/
static t_sprite	init_test_sprite(t_sprite_data *sprite_data, int id, double x, double y, double scale)
{
	t_sprite sprite;

	sprite.id = id;
	sprite.position.x = x;
	sprite.position.y = y;
	sprite.scale = scale;
	if (sprite_data[id].width * scale > SCREEN_HEIGHT)	
		sprite.scale = (double)SCREEN_HEIGHT/sprite_data[id].width;
	if (sprite_data[id].height * scale > SCREEN_HEIGHT)//limiting scale so sprite can never be higher than a wall
		sprite.scale = (double)SCREEN_HEIGHT/sprite_data[id].height;
	return (sprite);
}


/*
	freeing the sprite memory again - again just for testing (something is wrong here btw)
*/
void	free_img_matrix(t_sprite_data *sprite_data)
{
	int i, j;

	i = 0;
	while (sprite_data->img_matrix[i])
	{
		j = 0;
		while (sprite_data->img_matrix[j])
		{
			free(sprite_data->img_matrix[i][j]);
			j++;
		}
		free(sprite_data->img_matrix[i][j]);
		free(sprite_data->img_matrix[i]);
		i++;
	}
	free(sprite_data->img_matrix[i]);
	free(sprite_data->img_matrix);
}

/*
	finds the sprite with the next highest distance.
	Meant to be initiated with very high last_distance
	and have it loop through number of sprites
	returns pointer to the sprite object
*/
void *next_highest(t_sprite sprites[6], double *last_distance)
{
	double		tmpdist;
	void	*ptr;

	tmpdist = -1.0;
	for (int i = 0; i < 6; i++)
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
	t_sprite_data	sprite_data[6];
	t_sprite	sprites[6];
	t_sprite	**spriteptr;
	double		tmpdbl;
	t_vect		spritevect;

	//preparing the testsprites
	spriteptr = ft_calloc(sizeof(t_sprite *), 6);
	sprite_data[0] = init_test_sprite_data(set_color(0, 255, 0, 0));
	sprite_data[1] = init_test_sprite_data(set_color(0, 0, 255, 0));
	sprite_data[2] = init_test_sprite_data(set_color(0, 0, 0, 255));
	sprite_data[3] = init_test_sprite_data(set_color(0, 255, 255, 0));
	sprite_data[4] = init_test_sprite_data(set_color(0, 255, 0, 255));
	sprite_data[5] = init_test_sprite_data(set_color(0, 0, 255, 255));
	sprites[0] = init_test_sprite(sprite_data, 0, 230, 410, 10);
	sprites[1] = init_test_sprite(sprite_data, 1, 350, 310, 6);
	sprites[2] = init_test_sprite(sprite_data, 2, 700, 110, 7);
	sprites[3] = init_test_sprite(sprite_data, 3, 225, 810, 4);
	sprites[4] = init_test_sprite(sprite_data, 4, 563, 213, 5);
	sprites[5] = init_test_sprite(sprite_data, 5, 700, 700, 8);
	
	/*
		UP UNTIL THIS POINT, EVERYTHING SHOULD HAVE HAPPENED IN THE CONSTRUCTOR OF THE PROGRAM
	*/
	/*
		EVERYTHING BELOW NEEDS TO BE DONE EACH LOOP AFTER RENDERING THE WALLS
		anytime it counts up to 5, we will need to iterate through all sprites instead
	*/

	/*
		calculating the distance to each sprite
	*/
	for(int i=0; i < 6; i++){
		spritevect.x = sprites[i].position.x - data->player.pos.x;
		spritevect.y = sprites[i].position.y - data->player.pos.y;
		normalize_vector(&spritevect);
		sprites[i].distance = point_distance(data->player.pos, sprites[i].position);
	}
	/*
		sorting the sprites by distance
	*/
	tmpdbl = 2e30;
	for(int i=0; i < 6; i++)
		spriteptr[i] = (t_sprite *)next_highest(sprites, &tmpdbl);


	for(int i = 0; i < 6; i++)
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

		//find x position of sprite (on screen)
		(*spriteptr[i]).on_screen.x = angle_to_column(angle, data->player.vect);
		//find y position of sprite (on screen)
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
			draw_the_mother_fucking_sprite(data, sprite_data[(*spriteptr[i]).id],(*spriteptr[i]));
	}
	for(int i=0; i < 6; i++)
		free_img_matrix(&sprite_data[i]);
}

static double	get_dim_factor(double distance)
{
	double factor;

	factor = distance/1000;
	if (factor > 1)
		factor = 1;
	factor = 1 - factor;
	if (factor < 0.25)
		factor = 0.25;
	return (factor);
}

void	draw_the_mother_fucking_sprite(t_data *data, t_sprite_data sprite_data, t_sprite sprite)
{
	double	scalefactor;
	int		scaledwidth;
	int		scaledheight;
	int		xstart;
	int		ystart;

	scalefactor = sprite.scale / (sprite.distance / TILE_SIZE);
	scaledwidth = (int)(sprite_data.width * scalefactor);
	scaledheight = (int)(sprite_data.height * scalefactor);
	xstart = (int)sprite.on_screen.x - scaledwidth/2;
	ystart = (int)sprite.on_screen.y - scaledheight;
	for (int x = 0; x < scaledwidth; x++)
	{
		if  (xstart + x >= 0 && xstart + x < SCREEN_WIDTH && data->map.z_buffer[xstart + x] > sprite.distance) //checking if wall at this column is closer, and if it's offscreen
		{
			for (int j = 0; j < scaledheight; j++)
				if (ystart + j >= 0 &&ystart + j < SCREEN_HEIGHT)	//checking if y val is offscreen
				{
					double dimfactor;
					if ((*sprite_data.img_matrix[(int)(x/scalefactor)][(int)(j/scalefactor)]).a == 0) //not drawing if transparency value isn't 0
					{
						t_color dimmed;
						dimfactor = get_dim_factor(sprite.distance);
						dimmed = dim_color(*sprite_data.img_matrix[(int)(x/scalefactor)][(int)(j/scalefactor)], dimfactor);
						pixel_put(data->video.img_matrix, dimmed, xstart + x, ystart + j);
					}
				}
		}
	}
}