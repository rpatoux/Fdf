/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:02:57 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/09 20:34:37 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[++i])
		s2[i] = (*f)(s[i]);
	s2[i] = '\0';
	return (s2);
}
