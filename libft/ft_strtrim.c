/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:06:02 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 16:57:06 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*dst;
	const char		*str;
	unsigned int	i;
	unsigned int	j;

	str = s;
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_whitespace((char)*s++))
		i++;
	while (*s)
	{
		s++;
		j++;
	}
	s--;
	while (ft_whitespace((char)*s--))
		j--;
	if (!(dst = ft_strsub(str, i, j + 1)))
		return (NULL);
	return (dst);
}
