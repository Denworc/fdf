/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:13:13 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 19:43:26 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	const char	*str2;
	char		c;

	str2 = str;
	c = (char)s;
	while (*str)
		str++;
	while (str >= str2)
		if (*str == c)
			return ((char *)str);
		else
			str--;
	return (NULL);
}
