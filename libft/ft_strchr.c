/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:54:39 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/24 19:07:44 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	char c;

	c = (char)s;
	while (*str)
		if (*str == c)
			return ((char *)str);
		else
			str++;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
