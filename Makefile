CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra

# SRC subdirrectories #
VALIDATOR_FILES := validate_cub_file.c validate_map.c matrix_neighbour_check.c
VALIDATOR := $(addprefix validation/,$(VALIDATOR_FILES))

CONSTRUCTOR_FILES := constructor.c open_cub_file.c initiate_video.c \
					$(VALIDATOR) # open_texture_xmp.c
CONSTRUCTOR := $(addprefix constructor/,$(CONSTRUCTOR_FILES))
UTIL_FILES := file_to_heap.c find_char.c ft_color.c len_func.c \
				list_to_array.c match_str.c
UTIL := $(addprefix utils/,$(UTIL_FILES))
# SRC subdirrectories #

SRC_FILES	:= cube3d.c key_hooks.c $(CONSTRUCTOR) $(UTIL)
SRCDIR		:= src/
SRC			:= $(addprefix $(SRCDIR),$(SRC_FILES))
NAME		:= cube3d
LIBFT		:= $(SRCDIR)libs/libft/libft.a

ifeq ($(shell uname -s),Darwin)
	LBMLX	:= $(SRCDIR)libs/mlx/libmlx.a
	LIBS	:= -L /usr/X11/lib -lXext -lX11
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
