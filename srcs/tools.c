/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:56:12 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/20 23:09:42 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_destroy_img(t_var *my)
{
	mlx_destroy_image(my->mlx, my->img);
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp, &my->size_line,
		&my->endian);
}

float	define_x(t_var *my, int x, int y)
{
	return (my->zoom * (x - y) + (my->width / 2 + my->w_pic));
}

float	define_y(t_var *my, int x, int y)
{
	my->z = my->top * my->map[y][x];
	return ((my->zoom * ((x + y) - my->z)) + (my->height / 3 + my->h_pic));
}

void	write_data_pixel(t_var *my)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	if (my->color)
	{
		r = (my->color & 0xFF0000) >> 16;
		g = (my->color & 0xFF00) >> 8;
		b = (my->color & 0xFF);
	}
	if (my->x >= 0 && my->y >= 0 && my->x < my->width && my->y < my->height)
	{
		my->data[my->y * my->size_line + my->x * (my->bpp / 8)] = r;
		my->data[my->y * my->size_line + my->x * (my->bpp / 8) + 1] = g;
		my->data[my->y * my->size_line + my->x * (my->bpp / 8) + 2] = b;
	}
}

void	define_max(t_var *my, int x, int y)
{
	my->max_x = x;
	my->max_y = y;
	if (my->max_x == 0)
	{
		ft_putstr("Error, Invalid map\n");
		exit(EXIT_SUCCESS);
	}
}
