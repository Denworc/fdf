/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:54:49 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/28 11:57:29 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		dst[i] = (char)s[start + i];
		i++;
	}
	return (dst);
}
