/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:29:14 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/02 21:18:02 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (n > 0)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (*str1 == *str2 && n--)
		{
			if ((*str1 == '\0') || (!n))
				return (0);
			str1++;
			str2++;
		}
		return (*str1 - *str2);
	}
	return (0);
}
