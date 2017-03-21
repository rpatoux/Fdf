/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:35:17 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/15 00:35:29 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_power(int nb, int power)
{
	if (power > 1)
		return (nb * (ft_recursive_power(nb, power - 1)));
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (0);
}
