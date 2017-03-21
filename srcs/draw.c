/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:47:17 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/13 19:08:55 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		write_line_ver(t_var *my)
{
	int		cumul;
	int		i;

	cumul = my->dy / 2;
	i = 0;
	while (++i < my->dy + 1)
	{
		my->y += my->yinc;
		cumul += my->dx;
		if (cumul > my->dy + 1)
		{
			cumul -= my->dy;
			my->x += my->xinc;
		}
		write_data_pixel(my);
	}
}

static void		write_line_hor(t_var *my)
{
	int		cumul;
	int		i;

	cumul = my->dx / 2;
	i = 0;
	while (++i < my->dx + 1)
	{
		my->x += my->xinc;
		cumul += my->dy;
		if (cumul > my->dx + 1)
		{
			cumul -= my->dx;
			my->y += my->yinc;
		}
		write_data_pixel(my);
	}
}

static void		write_line(t_var *my)
{
	my->x = my->x1;
	my->y = my->y1;
	my->dx = my->x2 - my->x1;
	my->dy = my->y2 - my->y1;
	my->xinc = (my->dx > 0) ? 1 : -1;
	my->yinc = (my->dy > 0) ? 1 : -1;
	my->dx = abs(my->dx);
	my->dy = abs(my->dy);
	write_data_pixel(my);
	if (my->dx > my->dy)
		write_line_hor(my);
	else
		write_line_ver(my);
}

void			draw_line_x(t_var *my)
{
	int		x;
	int		y;

	x = -1;
	while (++x < my->max_x - 1)
	{
		y = -1;
		while (++y < my->max_y)
		{
			my->x1 = (int)define_x(my, x, y);
			my->x2 = (int)define_x(my, x + 1, y);
			my->y1 = (int)define_y(my, x, y);
			my->y2 = (int)define_y(my, x + 1, y);
			write_line(my);
		}
	}
}

void			draw_line_y(t_var *my)
{
	int		x;
	int		y;

	x = -1;
	while (++x < my->max_x)
	{
		y = -1;
		while (++y < my->max_y - 1)
		{
			my->x1 = define_x(my, x, y);
			my->x2 = define_x(my, x, y + 1);
			my->y1 = define_y(my, x, y);
			my->y2 = define_y(my, x, y + 1);
			write_line(my);
		}
	}
}
