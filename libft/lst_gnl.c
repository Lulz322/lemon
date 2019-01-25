//
// Created by bender on 1/24/19.
//
#include "includes/libft.h"
#include "../includes/get_next_line.h"


void		ft_list_add_last(t_gnl **save, t_gnl *elem)
{
	t_gnl *list;

	list = *save;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
}

t_gnl	*ft_create_list(int fd)
{
	t_gnl *list;

	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->tempo = ft_strnew(0);
	list->text = NULL;
	list->next = NULL;
	return (list);
}
