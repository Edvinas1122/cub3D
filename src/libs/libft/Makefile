# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 22:19:07 by emomkus           #+#    #+#              #
#    Updated: 2022/01/25 19:34:47 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
		ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
		ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
		ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
		ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
		ft_toupper.c ft_calloc.c  ft_isdigit.c  ft_memchr.c   ft_memset.c \
		ft_putstr_fd.c   ft_strjoin.c  ft_strmapi.c  ft_strtrim.c ft_atol.c \
		ft_strjoin_free.c
OBJ = $(SRC:.c=.o)
BONUSFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c

BONUSOFILES = $(BONUSFILES:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOFILES)
	ar -rc $(NAME) $(BONUSOFILES) $(OBJ)
	
rebonus: fclean bonus

clean:
	rm -f $(OBJ)
	rm -f $(BONUSOFILES)
fclean:
	rm -f $(OBJ)
	rm -f $(BONUSOFILES)
	rm -f $(NAME)

re:		fclean all

%.o: %.c
	gcc $(FLAG) -c $^ -o $@

.PHONY:			all bonus clean fclean
