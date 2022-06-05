CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -g
SRC_FILES	:= cube3d.c constructor/constructor.c
SRCDIR		:= cubeh/libs/
SRC			:= $(addprefix $(SRCDIR),$(SRC_FILES))
NAME		:= cube3d
LIBFT		:= $(SRCDIR)libft/libft.a

ifeq ($(shell uname -s),Darwin)
	LBMLX	:= $(SRCDIR)mlx/libmlx.a
	LIBS	:= -L /usr/X11/lib -lXext -lX11
else
	LBMLX	:= $(SRCDIR)mlx/libmlx_Linux.a
	LIBS	:= -lXext -lX11 -lm
endif

all: $(NAME)

re: clean $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(SRCDIR)libft/

clean:
	rm -f $(NAME)

fclean: clean
