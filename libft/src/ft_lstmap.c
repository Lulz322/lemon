/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:34:05 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 17:34:07 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*newelem;

	if (!lst)
		return (NULL);
	newelem = f(lst);
	new = newelem;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newelem->next = f(lst)))
		{
			free(newelem->next);
			return (NULL);
		}
		newelem = newelem->next;
	}
	return (new);
}
