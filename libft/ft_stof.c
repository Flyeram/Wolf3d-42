/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:29:56 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/08 15:09:02 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_stof(char *str)
{
	char	**split;
	double	real;
	double	flo;

	split = ft_strsplit(str, '.');
	if (ft_arraylen(split) < 2)
		return (ft_atoi(split[0]));
	real = ft_atoi(split[0]);
	flo = (double)ft_atoi(split[1]);
	while (flo > 10.0)
	{
		flo /= 10.0;
	}
	if (real < 0)
		flo *= -1;
	return (real + (flo / 10.0));
}
