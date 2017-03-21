/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:38:14 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/21 16:37:51 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_errno(char *argv)
{
	char	*str;

	if (open(argv, O_RDONLY) == -1)
	{
		if (errno != EACCES)
		{
			str = ft_strdup("Error, ");
			write(2, str, ft_strlen(str));
			write(2, argv, ft_strlen(argv));
			ft_putchar(' ');
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			ft_putchar('\n');
			ft_strdel(&str);
			exit(EXIT_SUCCESS);
		}
	}
}

static void		ft_moove(int keycode, t_var *my)
{
	if (keycode == 126 || keycode == 125)
		my->h_pic += keycode == 126 ? -20 : 20;
	if (keycode == 123 || keycode == 124)
		my->w_pic += keycode == 124 ? 20 : -20;
	if (keycode == 78 || keycode == 69)
		my->top += keycode == 69 ? 0.1 : -0.1;
}

static void		ft_color_map(int keycode, t_var *my)
{
	if (keycode == 18)
		my->color = 0xFF6600;
	if (keycode == 19)
		my->color = 0x660066;
	if (keycode == 20)
		my->color = 0x0000FF;
	if (keycode == 21)
		my->color = 0x33FF00;
	if (keycode == 22)
		my->color = 0xFF358B;
	if (keycode == 23)
		my->color = 0xFFFF00;
	if (keycode == 26)
		my->color = 0x00FFFF;
	if (keycode == 28)
		my->color = 0xFF0000;
	if (keycode == 25)
		my->color = 0x333333;
}

static int		ft_keyhook(int keycode, t_var *my)
{
	ft_destroy_img(my);
	ft_color_map(keycode, my);
	ft_moove(keycode, my);
	if (keycode == 53)
	{
		free(my);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 116 || keycode == 121)
	{
		if (my->zoom - 2 > 0 && keycode == 121)
			my->zoom -= 2;
		else if (keycode == 116)
			my->zoom += 2;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_var	*my;
	char	*error;

	if (!(my = (t_var*)malloc(sizeof(t_var))))
		return (0);
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf ./map.fdf\n");
		return (0);
	}
	ft_init_env(my);
	ft_errno(argv[1]);
	ft_count_max(argv[1], my, 0, 0);
	if (ft_parsing(argv[1], my, 0, -1) == -1)
		return (0);
	ft_init(my);
	ft_new(my);
	mlx_key_hook(my->win, ft_keyhook, my);
	mlx_loop_hook(my->mlx, ft_new, my);
	mlx_loop(my->mlx);
	return (0);
}
