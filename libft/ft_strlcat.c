/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:08:45 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 13:47:08 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len++;
	if (len < size)
	{
		while (len + i + 1 < size && src[i])
		{
			dst[len + i] = (char)src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	return (len + ft_strlen(src));
}
