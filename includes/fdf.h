/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:13:39 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/21 16:01:20 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx_macos_sierra/mlx.h"
# include "../libft/libft.h"
# include <errno.h>

typedef struct	s_var
{
	int				x;
	int				y;
	int				z;

	int				h_pic;
	int				w_pic;

	void			*mlx;
	void			*win;
	void			*img;

	int				endian;
	int				bpp;
	int				size_line;

	int				zoom;

	int				height;
	int				width;

	char			*data;
	char			*sign;

	int				win_x;
	int				win_y;

	int				**map;
	int				max_x;
	int				max_y;

	int				x1;
	int				x2;
	int				y1;
	int				y2;

	int				dx;
	int				dy;

	int				color;
	float			top;

	int				xinc;
	int				yinc;
}				t_var;

void			write_data_pixel(t_var *my);
float			define_y(t_var *my, int x, int y);
float			define_x(t_var *my, int x, int y);
int				main(int argc, char **argv);
void			ft_count_max(char *argv, t_var *my, int x, int y);
int				ft_parsing(char *argv, t_var *my, int x, int y);
void			ft_print_tab(char **tab);
void			ft_print_tab_int(t_var *my);
int				ft_new(t_var *my);
static void		write_line(t_var *my);
void			draw_line_x(t_var *my);
void			draw_line_y(t_var *my);
static void		write_info(t_var *my);
void			ft_destroy_img(t_var *my);
int				check_hexa(char *str, int k);
void			ft_init_env(t_var *my);
void			ft_init(t_var *my);
void			define_max(t_var *my, int x, int y);

#endif
