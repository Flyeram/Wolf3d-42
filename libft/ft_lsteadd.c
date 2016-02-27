/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsteadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:37:56 by tbalu             #+#    #+#             */
/*   Updated: 2015/12/08 12:59:35 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lsteadd(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
	new->next = NULL;
}
