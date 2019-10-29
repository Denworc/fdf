/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:58:26 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/22 17:14:13 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = (char *)src;
	i = 0;
	while (i < len)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)&(str[i]));
		i++;
	}
	return (NULL);
}
