/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:16:50 by rpatoux           #+#    #+#             */
/*   Updated: 2016/11/14 20:55:05 by rpatoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	list = new;
	while (lst->next)
	{
		lst = lst->next;
		list->next = (*f)(lst);
		list = list->next;
	}
	return (new);
}
