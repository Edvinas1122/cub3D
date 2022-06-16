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

void	menu_pop(t_data *data)
{
	static int i;

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
		mlx_mouse_move(data->mlx.win, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		mlx_mouse_hide(data->mlx.win, 0);
		i = 0;
	}
}

void	close_win(t_data *data)
{
	ft_putstr_fd("Exiting program\n", 1);
	destructor(data);
}