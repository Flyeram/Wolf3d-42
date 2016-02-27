/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:47:39 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 16:24:10 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;
	void	*cnt_cpy;

	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		cnt_cpy = ft_memalloc(content_size);
		cnt_cpy = ft_memcpy(cnt_cpy, content, content_size);
		new_elem->content = cnt_cpy;
		new_elem->content_size = content_size;
	}
	new_elem->next = NULL;
	return (new_elem);
}
