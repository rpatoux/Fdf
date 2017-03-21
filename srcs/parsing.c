/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:50:52 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/21 16:38:23 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_strlenspace(char *line, int i)
{
	int		n;
	int		offset;
	int		j;

	n = 0;
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
		{
			n++;
			while (ft_isdigit(line[i]))
				i++;
			i--;
		}
		if (line[i] == ',')
		{
			while (line[i] && line[i] != ' ')
				i++;
		}
	}
	return (n);
}

void	ft_count_max(char *argv, t_var *my, int x, int y)
{
	char	*line;
	int		l;
	int		fd;
	int		j;

	line = NULL;
	j = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) && line && ++y)
	{
		l = ft_strlenspace(line, -1);
		if (l != 0 && j == 0)
			j = l;
		if (j != l)
		{
			ft_putstr("Error : Invalid map\n");
			exit(EXIT_SUCCESS);
		}
		if (l > x)
			x = l;
		if (line)
			free(line);
	}
	close(fd);
	define_max(my, x, y);
}

int		check_hexa(char *str, int k)
{
	int		length;

	length = 0;
	k++;
	if (!(str[k]))
		return (0);
	else if (str[k] && str[k] != ',')
		return (-1);
	k++;
	if (str[k] && str[k + 1] && (str[k] != '0' || str[k + 1] != 'x'))
		return (-1);
	k++;
	while (str[k])
	{
		if ((str[k] >= '0' && str[k] <= '9') || (str[k] >= 'A' &&
			str[k] <= 'F') || (str[k] >= 'a' && str[k] <= 'f'))
			length++;
		k++;
	}
	if (length != 6)
		return (-1);
	return (0);
}

int		ft_fillmap(t_var *my, char **split, int y)
{
	int		j;
	int		x;
	int		k;
	char	*error;

	error = "Error : Invalid map\n";
	x = 0;
	j = 0;
	while (x < my->max_x && split[j])
	{
		k = 0;
		if ((my->map[y][x] = ft_atoi(split[j], &k)) == 0 &&
			split[j][k] && split[j][k] != '0')
			return (-1);
		if (check_hexa(split[j], k) == -1)
		{
			ft_putstr("error: invalid character or hexadecimal\n");
			return (-1);
		}
		j++;
		x++;
	}
	return (0);
}

int		ft_parsing(char *argv, t_var *my, int i, int y)
{
	char	*line;
	char	**split;
	int		fd;

	if (!argv)
		return (-1);
	fd = open(argv, O_RDONLY);
	if (!(my->map = (int **)malloc(sizeof(int*) * my->max_y)))
		return (0);
	while (get_next_line(fd, &line) && ++y != -1)
	{
		if (!(my->map[y] = (int*)malloc(sizeof(int) * my->max_x)))
			return (0);
		if ((split = ft_strsplit(line, ' ')) && ft_fillmap(my, split, y) == -1)
			return (-1);
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
		free(line);
	}
	close(fd);
	return (0);
}
