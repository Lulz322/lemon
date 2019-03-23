/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:34:24 by iruban            #+#    #+#             */
/*   Updated: 2018/11/02 17:34:43 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*newl;
	t_list	*next;

	if (alst || del)
	{
		newl = *alst;
		while (newl)
		{
			next = newl->next;
			del(newl->content, newl->content_size);
			free(newl);
			newl = next;
		}
		*alst = NULL;
	}
}
