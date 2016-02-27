/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:55:50 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 17:20:17 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lstnext;

	lstnext = (*alst)->next;
	while (lstnext != NULL)
	{
		ft_lstdelone(alst, del);
		*alst = lstnext;
		lstnext = (*alst)->next;
	}
	ft_lstdelone(alst, del);
}
