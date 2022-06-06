#ifndef CUBE3D_CONSTRUCTOR_H
# define CUBE3D_CONSTRUCTOR_H

# include "../cube3d.h"
# include "validation/validation.h"

/* Struct initiator */
void		constructor(s_data **data, char **argv);

/* Member in constructor */
t_map		**open_cub_file(char **argv);
t_textures	open_texture_xmp(t_list **file);
t_video		*set_video_window(t_mlx *mlx);


#endif