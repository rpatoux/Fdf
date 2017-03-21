/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:17:10 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/21 16:17:11 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		result(char **line, char *buf)
{
	char	*eol;

	eol = ft_strchr(buf, '\n');
	if (eol != NULL)
	{
		*eol = '\0';
		*line = ft_strdup(buf);
		ft_memmove(buf, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(buf) > 0)
	{
		*line = ft_strdup(buf);
		*buf = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	char		buffer[BUFF_SIZE + 1];
	char		*line_tmp;
	int			ret;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (buf == NULL)
		buf = ft_strnew(0);
	while (!ft_strchr(buf, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		line_tmp = ft_strjoin(buf, buffer);
		free(buf);
		buf = line_tmp;
	}
	return (result(line, buf));
}
