/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:45:45 by rpatoux           #+#    #+#             */
/*   Updated: 2017/03/20 23:28:08 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (j);
}

static int	size(char const *s, char c, int i)
{
	int		j;

	j = 0;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * count_w(s, c) + 1)))
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c)
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) * size(s, c, i) + 1)))
				return (0);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
			i--;
		}
	tab[j] = NULL;
	return (tab);
}
