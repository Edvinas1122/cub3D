#include "constructor.h"

/* 
	Initiates t_data struct 
*/
void	constructor(t_data *data, char **argv)
{
	data->map = open_cub_file(argv[1]);
	data->player.pos = 
}