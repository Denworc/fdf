/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:44:23 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 14:11:30 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*src;
	const char	*dst;
	size_t		n;

	if (!*little)
		return ((char *)big);
	if (*little)
		while (*big && len)
		{
			dst = little;
			n = len;
			len--;
			src = big;
			while ((*src++ == *dst++) && (n--))
				if (!(*dst))
					return ((char *)big);
			big++;
		}
	return (NULL);
}
