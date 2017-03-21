/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:48:57 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/13 16:54:35 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s1;

	if (!(s1 = (void*)malloc(sizeof(void) * size)) || (!size))
		return (NULL);
	ft_bzero(s1, size);
	return (s1);
}
