/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:08:40 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/13 23:17:40 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int ibis;

	j = 0;
	i = -1;
	if (to_find[0] == 0)
		return (str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			ibis = i;
			while (str[i++] == to_find[j] && to_find[j] != 0)
				j++;
			if (to_find[j] == '\0')
				return (&str[ibis]);
			else
			{
				i = ibis;
				j = 0;
			}
		}
	}
	return (NULL);
}
