/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 22:40:54 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/13 23:28:06 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbchar(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char		*buff;
	int			len;
	long int	num;

	num = n;
	len = nbchar(n);
	if (!(buff = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (num == 0)
		buff[0] = '0';
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num < 0)
	{
		buff[0] = '-';
		num = -num;
	}
	num *= 10;
	buff[len] = '\0';
	while ((num /= 10) > 0)
		buff[--len] = (num % 10) + '0';
	return (buff);
}
