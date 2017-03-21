/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:03:51 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/13 19:05:29 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		write_info_to_window(t_var *my)
{
	mlx_string_put(my->mlx, my->win, (my->width / 3), 5, 0xFFFFFF,
		"Pour toutes modifications veuillez utiliser les touches suivantes :");
	mlx_string_put(my->mlx, my->win, 5, 150, 0xFFFFFF, "- ZOOM -> Page up");
	mlx_string_put(my->mlx, my->win, 5, 175, 0xFFFFFF, "- DEZOOM -> Page down");
	mlx_string_put(my->mlx, my->win, 5, 375, 0xFFFFFF, "- HAUT -> Fleche haut");
	mlx_string_put(my->mlx, my->win, 5, 400, 0xFFFFFF, "- BAS -> Fleche bas");
	mlx_string_put(my->mlx, my->win, 5, 425, 0xFFFFFF,
		"- DROITE -> Fleche Droite");
	mlx_string_put(my->mlx, my->win, 5, 450, 0xFFFFFF,
		"- GAUCHE -> Fleche gauche");
	mlx_string_put(my->mlx, my->win, 5, 650, 0xFFFFFF, "- HAUTEUR -> + ou -");
	mlx_string_put(my->mlx, my->win, 5, 850, 0xFFFFFF, "- COULEUR -> 1 a 9");
}

void			write_info(t_var *my)
{
	write_info_to_window(my);
}

int				ft_new(t_var *my)
{
	draw_line_x(my);
	draw_line_y(my);
	mlx_put_image_to_window(my->mlx, my->win, my->img, 0, 0);
	write_info(my);
	return (0);
}

void			ft_init_env(t_var *my)
{
	my->color = 0xFFFFFF;
	my->zoom = 15;
	my->top = 0.2f;
	my->h_pic = 0;
	my->w_pic = 0;
}

void			ft_init(t_var *my)
{
	my->width += (my->max_x * 100 < 1800) ? my->max_x * 100 : 1800;
	my->height += (my->max_y * 100 < 1100) ? my->max_x * 100 : 1100;
	my->size_line = my->width * (my->bpp / 8);
	my->mlx = mlx_init();
	my->win = mlx_new_window(my->mlx, my->width, my->height, "fdf - rpatoux");
	my->img = mlx_new_image(my->mlx, my->width, my->height);
	my->data = mlx_get_data_addr(my->img, &my->bpp, &my->size_line,
		&my->endian);
}
