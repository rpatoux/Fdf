/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:13:46 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/13 23:19:20 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	if (!s || !f)
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
