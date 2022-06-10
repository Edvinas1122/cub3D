/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimenting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:01:00 by kmeixner          #+#    #+#             */
/*   Updated: 2022/06/09 22:13:50 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "experimenting.h"
double	intersection_distances(t_mlx *mlx, t_point *pos, t_vector *dir);
t_point	*find_and_draw_intersections(t_mlx *mlx, t_vector *dir);
void	draw_ray_3D(t_data *img, double distance, int x);

char	g_testarr[8][9]= {
{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
{'1', '0', '1', '0', '0', 'N', '0', '1', '1'},
{'1', '0', '1', '0', '0', '0', '0', '1', '1'},
{'1', '0', '0', '0', '0', '0', '0', '1', '1'},
{'1', '1', '1', '1', '1', '1', '1', '1', '1'}
};
// char	g_testarr[10][17]= {
// {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '1', '0', '0', 'N', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
// {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
// };

/*
	checks if the given point belongs to a wall
*/
int	check_if_wall(t_point *point)
{
	int x = point->x / 100;
	int y = point->y / 100;

	if (g_testarr[y][x] == '1')
		return (1);
	else
		return (0);
}

/*
	draws the individual boxes for each tile
*/
void	draw_box(t_data *img, int x, int y)
{
	for (int i = 0; i < 100; i++){
		my_mlx_pixel_put(img, x*100+i, y*100-1, 0x00000000);
		my_mlx_pixel_put(img, x*100+i, y*100, 0x00000000);
		my_mlx_pixel_put(img, x*100+i, y*100+1, 0x00000000);
		my_mlx_pixel_put(img, x*100-1, y*100+i, 0x00000000);
		my_mlx_pixel_put(img, x*100, y*100+i, 0x00000000);
		my_mlx_pixel_put(img, x*100+1, y*100+i, 0x00000000);
	}
	if (g_testarr[y][x] == '1')
		for (int i = 1; i < 99; i++)
			for(int j = 1; j < 99; j++)
				my_mlx_pixel_put(img, x*100+i, y*100+j, 0x00333333);
	else if (g_testarr[y][x] == '0' || g_testarr[y][x] == 'N')
		for (int i = 1; i < 99; i++)
			for(int j = 1; j < 99; j++)
				my_mlx_pixel_put(img, x*100+i, y*100+j, 0x00C0C0C0);
}

/*
	draw 2d map
*/
void	draw_map(t_mlx *mlx)
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 8; j++)
			draw_box(&mlx->img, i, j);
}
/*
	sets the coordinates of the player
*/
void	player_set_pos(int x, int y, t_point *player)
{
	player->x = x * 100 + 49;
	player->y = y * 100 + 49;
}
/*
	finds the player in the bitmap
*/
void	find_player(t_point *player)
{
	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 8; j++)
			if (g_testarr[j][i] == 'N')
				player_set_pos(i, j, player);
}
/*
	casts lots of rays and calls draw_ray_3D for each
*/
void	cast_cone(t_mlx *mlx, t_point *player, double fov, int rays)
{
	t_vector	tmpdir;
	double		step;
	t_point		*impact;
	int	i = 0;

	tmpdir.x = mlx->dir->x;
	tmpdir.y = mlx->dir->y;
	step = fov / rays;
	rotate_vector(&tmpdir, (-1)*(fov/2));
	while ((i * step) < fov)
	{
		impact = find_and_draw_intersections(mlx, &tmpdir);
		draw_ray_3D(&mlx->img_3D, point_distance(player, impact), i);
		free(impact);
		rotate_vector(&tmpdir, step);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_3D.img, 900, 0);
	// cast_ray(mlx, player, &tmpdir);
}

/*
	draws the player on 2D and calls the raycaster
*/
void	draw_player(t_mlx *mlx, t_data *img, t_point *player, int size)
{
	int	xstart = player->x - size / 2;
	int	ystart = player->y - size / 2;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			my_mlx_pixel_put(img, xstart + i, ystart + j, 0x00FF0000);
	// cast_ray(mlx, player, mlx->dir);
	cast_cone(mlx, player, FOV, WINDOW_WIDTH - 900);
}

/*
	rotates player, calls all draw functions afterwards
*/
void	rotate_player(t_mlx *mlx, int keycode, double angle)
{
	if (keycode == 123)
		rotate_vector(mlx->dir, -1*angle);
	if (keycode == 124)
		rotate_vector(mlx->dir, angle);
	draw_map(mlx);
	draw_player(mlx, &mlx->img, mlx->player, 5);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

void	move_forward(t_mlx *mlx)
{
	mlx->player->x += mlx->dir->x * MOVE_DISTANCE;
	mlx->player->y += mlx->dir->y * MOVE_DISTANCE;
}

void	move_backwards(t_mlx *mlx)
{
	mlx->player->x -= mlx->dir->x * MOVE_DISTANCE;
	mlx->player->y -= mlx->dir->y * MOVE_DISTANCE;
}

void	move_left(t_mlx *mlx)
{
	t_vector tmp;

	tmp.x = mlx->dir->x;
	tmp.y = mlx->dir->y;
	rotate_vector(&tmp, 90);
	mlx->player->x -= tmp.x * MOVE_DISTANCE;
	mlx->player->y -= tmp.y * MOVE_DISTANCE;
}

void	move_right(t_mlx *mlx)
{
	t_vector tmp;

	tmp.x = mlx->dir->x;
	tmp.y = mlx->dir->y;
	rotate_vector(&tmp, -90);
	mlx->player->x -= tmp.x * MOVE_DISTANCE;
	mlx->player->y -= tmp.y * MOVE_DISTANCE;
}

/*
	calls the respective move function depending on key pressed,
	calls all draw functions afterwards
*/
void	move_player(t_mlx *mlx, int keycode)
{
	if (keycode == 0)
		move_left(mlx);
	if (keycode == 2)
		move_right(mlx);
	if (keycode == 1 || keycode == 125)
		move_backwards(mlx);
	if (keycode == 13 || keycode == 126)
		move_forward(mlx);
	draw_map(mlx);
	draw_player(mlx, &mlx->img, mlx->player, 5);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

int	main(void)
{
	t_mlx	mlx;
	mlx.player = malloc(sizeof(t_point));
	mlx.dir = malloc(sizeof(t_vector));
	mlx.dir->y = 0;
	mlx.dir->x = 1;
	normalize_vector(mlx.dir);
	find_player(mlx.player);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FUCKYEAHLETSGO");
	mlx.img.img = mlx_new_image(mlx.mlx, 900, WINDOW_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx.img_3D.img = mlx_new_image(mlx.mlx, 1280, WINDOW_HEIGHT);
	mlx.img_3D.addr = mlx_get_data_addr(mlx.img_3D.img, &mlx.img_3D.bits_per_pixel, &mlx.img_3D.line_length, &mlx.img_3D.endian);
	draw_map(&mlx);
	draw_player(&mlx, &mlx.img, mlx.player, 5);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, 0, keys, &mlx);
	mlx_loop(mlx.mlx);
}

/*
	goes in the given direction through every intersection until a wall is hit, returning the point of impact
*/
t_point	*find_and_draw_intersections(t_mlx *mlx, t_vector *dir)
{
	t_point	*tmp;
	tmp = malloc(sizeof(t_point));
	double	tmpdist;
	tmp->x = mlx->player->x;
	tmp->y = mlx->player->y;
	while (42)
	{
		tmpdist = intersection_distances(mlx, tmp, dir);
		tmp->x += (tmpdist * dir->x);
		tmp->y += (tmpdist * dir->y);
		my_mlx_pixel_put(&mlx->img, tmp->x, tmp->y, 0x0000FF00);
		tmp->x += dir->x;
		tmp->y += dir->y;
		if (check_if_wall(tmp))
			break ;
	}
	return (tmp);
}

/*
	draws a line on the screen, giving the wall a size depending on distance
*/
void	draw_ray_3D(t_data *img, double distance, int x)
{
	int	i;
	int	ceilingcolour;
	int	wallcolour;
	int floorcolour;
	double wallsize;

	ceilingcolour = 0x00B7CCDF;
	wallcolour = 0x00483320;
	floorcolour = 0x00008080;
	wallsize = WINDOW_HEIGHT/(distance/100);
	i = 0;
	int start;
	int end;
	start = ((-1)*wallsize)/2 + WINDOW_HEIGHT/2;
	if (start < 0)
		start = 0;
	end = wallsize/2 + WINDOW_HEIGHT/2;
	if (end >= WINDOW_HEIGHT)
		end = WINDOW_HEIGHT - 1;
	
	while (i < WINDOW_HEIGHT)
	{
		if (i < start)
			my_mlx_pixel_put(img, x, i, ceilingcolour);
		else if (i < end)
			my_mlx_pixel_put(img, x, i, wallcolour);
		else
			my_mlx_pixel_put(img, x, i, floorcolour);
			
		i++;
	}
}
/*
	finds the next intersection in given direction and returns distance to it
*/
double	intersection_distances(t_mlx *mlx, t_point *pos, t_vector *dir)
{
	double	angle;
	double	dist_to_vert;
	double	dist_to_hor;
	double	vert_factor;
	double	hor_factor;

	angle = atan2(dir->y*-1, dir->x);
	if (dir->x >= 0 && dir->y >= 0)
		angle *= -1;
	if (dir->x < 0 && dir->y >= 0)
		angle = ((-1) * M_PI - angle) * (-1);
	if (dir->x < 0 && dir->y < 0)
		angle = M_PI - angle;

	if (dir->x >= 0)
		vert_factor = (100 - ((int)(pos->x)%100));
	else
		vert_factor = ((int)(pos->x)%100);
	if (dir->y >= 0)
		hor_factor = (100 - ((int)(pos->y)%100));
	else
		hor_factor = ((int)(pos->y)%100);
	
	dist_to_vert = 100/(cos(angle));
	dist_to_hor = 100/(cos(M_PI/2 - angle));
	vert_factor /= 100;
	hor_factor /= 100;
	dist_to_vert = fabs(dist_to_vert * vert_factor);
	dist_to_hor = fabs(dist_to_hor * hor_factor);
	if (dist_to_vert < dist_to_hor)
		return (dist_to_vert);
	else
		return (dist_to_hor);
}