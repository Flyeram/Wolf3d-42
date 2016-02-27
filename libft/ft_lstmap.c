/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:12:13 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/29 12:30:04 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	del(void *list, size_t size)
{
	free(list);
	size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstnew;
	t_list	*list;

	if (lst == NULL)
		return (NULL);
	list = NULL;
	while (lst != NULL)
	{
		if (!(lstnew = (*f)(lst)))
		{
			ft_lstdel(&list, del);
			return (NULL);
		}
		ft_lsteadd(&list, lstnew);
		lst = lst->next;
	}
	return (list);
}
