/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:14:51 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 19:47:39 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		i;

	num = n;
	i = 0;
	if (n < 0)
		i = 1;
	while ((n > 9 || n < -9) && ++i)
	{
		n /= 10;
	}
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
