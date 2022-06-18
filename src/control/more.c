#include "control.h"

void	pop_minimap(t_data *data)
{
	static int	iteration;

	if (!iteration)
	{
		data->util.minimap_size *= 4;
		iteration = 1;
	}
	else
	{
		data->util.minimap_size /= 4;
		iteration = 0;
	}
}

void	toggle_door(t_data *data)
{
	int x;
	int y;
	t_vect	tmp;

	tmp.x = data->player.pos.x + data->player.vect.x * (TILE_SIZE);
	tmp.y = data->player.pos.y + data->player.vect.y * (TILE_SIZE);
	x = tmp.x / TILE_SIZE;
	y = tmp.y / TILE_SIZE;
	if (data->map.bit_map[y][x] == '2')
	{
		if (data->map.doormap[y][x].closed_percentage == 100)
		{
			data->map.doormap[y][x].moving = -5;
			play_audio("./audio/door.wav", 2);
		}
		else if (data->map.doormap[y][x].closed_percentage == 0)
		{
			data->map.doormap[y][x].moving = 5;
			play_audio("./audio/door.wav", 2);
		}
		else if (data->map.doormap[y][x].moving > 0)
			data->map.doormap[y][x].moving = -5;
		else if (data->map.doormap[y][x].moving < 0)
			data->map.doormap[y][x].moving = 5;
	}
}

void	menu_pop(t_data *data)
{
	static int i;
	long			x;
	long			y;

	x = SCREEN_WIDTH / 2;
	y = SCREEN_HEIGHT / 2;
	if (!i) 
	{
		data->util.game_state = 0;
		mlx_hook(data->mlx.win, 6, (1L<<6), player_mouse_action_stop, data);
		mlx_mouse_show(data->mlx.win, 0);
		i = 1;
	}
	else
	{
		data->util.game_state = 1;
		mlx_hook(data->mlx.win, 6, (1L<<6), player_mouse_action, data);
		mlx_mouse_move(data->mlx.win, (void*)x, y, 0);
		mlx_mouse_hide(data->mlx.win, 0);
		i = 0;
	}
}

void	close_win(t_data *data)
{
	ft_putstr_fd("Exiting program\n", 1);
	destructor(data);
}