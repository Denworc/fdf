/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:19:37 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/06 16:57:59 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *n, size_t len)
{
	int max;

	max = *n;
	while (len--)
	{
		if (*n > max)
			max = *n;
		n++;
	}
	return (max);
}
