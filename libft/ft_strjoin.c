/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:28:06 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/28 17:39:51 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	dst = NULL;
	if (s1 && s2)
	{
		if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		dst = ft_strcat(dst, (char*)s1);
		dst = ft_strcat(dst, (char*)s2);
		return (dst);
	}
	return (NULL);
}
