CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -O3

# SRC subdirrectories #
VALIDATOR_FILES := validate_cub_file.c validate_map.c matrix_neighbour_check.c
VALIDATOR := $(addprefix validation/,$(VALIDATOR_FILES))

CONSTRUCTOR_FILES := constructor.c open_cub_file.c initiate_video.c destructor.c \
					open_textures_xmp.c set_utils.c $(VALIDATOR) 
CONSTRUCTOR := $(addprefix constructor/,$(CONSTRUCTOR_FILES))
DISPLAY_FILES := display.c minimap.c raycast.c draw_vertical_line.c intersection_distances.c \
				vertical_line_wall.c
DISPLAY := $(addprefix display/,$(DISPLAY_FILES))
CONTROL_FILES := key_hooks.c move_player.c rotate_player.c more.c
CONTROL := $(addprefix control/,$(CONTROL_FILES))
UTIL_FILES := file_to_heap.c find_char.c ft_color.c len_func.c \
				list_to_array.c match_str.c pixel_matrix.c delete_list.c \
				math_functions.c game_mech.c
UTIL := $(addprefix utils/,$(UTIL_FILES))
# SRC subdirrectories #

SRC_FILES	:= cube3d.c $(CONSTRUCTOR) $(DISPLAY) $(CONTROL) $(UTIL)
SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR),$(SRC_FILES))
NAME		:= cube3d
LIBFT		:= $(SRCDIR)libs/libft/libft.a

ifeq ($(shell uname -s),Darwin)
	LBMLX	:= $(SRCDIR)libs/mlx/libmlx.a
	LIBS	:= -Lsrc/libs/mlx -framework OpenGL -framework AppKit
else
	LBMLX	:= $(SRCDIR)libs/mlx/libmlx_Linux.a
	LIBS	:= -lXext -lX11 -lm
endif

all: $(NAME)

re: clean $(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(SRCDIR)libs/libft/

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

