/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:25:53 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 14:01:56 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *src;
	const char *dst;

	if (!*little)
		return ((char *)big);
	if (*little)
		while (*big)
		{
			dst = little;
			src = big;
			while (*src++ == *dst++)
				if (!(*dst))
					return ((char *)big);
			big++;
		}
	return (NULL);
}
