/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:02:10 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 14:31:49 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*sorc;

	i = 0;
	dest = (char *)dst;
	sorc = (const char *)src;
	if (dest <= sorc)
	{
		while (i < len)
		{
			dest[i] = sorc[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = sorc[i - 1];
			i--;
		}
	}
	return (dst);
}
