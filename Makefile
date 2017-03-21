# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 16:20:24 by rpatoux           #+#    #+#              #
#    Updated: 2017/03/13 21:49:29 by rpatoux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ./srcs/main.c \
	   ./srcs/parsing.c \
	   ./srcs/init.c \
	   ./srcs/draw.c \
	   ./srcs/tools.c \

HEADER = ./includes/fdf.h

FLAGS = -Wall -Wextra -Werror -I./libft -I./fdf.h

OBJ = $(SRCS:.c=.o)

VERSION_GET := $(shell sw_vers | grep "ProductVersion:" | tail -c 8 | head -c 5)
SIERRA = 10.12
EL_CAPITAN = 10.11
MLX_S = minilibx_macos_sierra
MLX_E = minilibx_macos_el_captain
MLX = minilibx_macos_el_captain
ifeq ($(VERSION_GET), $(SIERRA))
	MLX = $(MLX_S)
else
	MLX = $(MLX_E)
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L $(MLX) -lmlx -framework OpenGL -framework \
		AppKit $(MLX)/libmlx.a ./libft/libft.a
	echo "Fdf compilation done"

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make clean -C $(MLX)
	rm -f $(NAME)

re: fclean all
