/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:33:34 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 16:58:38 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	len;
	size_t	i;
	size_t	let;

	if (s == NULL)
		return (NULL);
	len = ft_getwords(s, c);
	i = 0;
	if (!(dst = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	dst[len] = (char*)'\0';
	while (len--)
	{
		while ((*s != '\0') && ((char)*s == c))
			s++;
		let = ft_getlet(s, c);
		if (!(dst[i] = (char *)ft_memalloc(sizeof(char) * (let + 1))))
			return (NULL);
		ft_memcpy(dst[i], s, let);
		dst[i++][let] = '\0';
		s = s + let;
	}
	return (dst);
}
