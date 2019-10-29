/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:50:24 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/02 19:17:23 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str2;

	if (!(str2 = ft_strsub(s1, 0, ft_strlen(s1))))
		return (NULL);
	ft_strcpy(str2, s1);
	return (str2);
}
