/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:37:00 by smaksymy          #+#    #+#             */
/*   Updated: 2016/11/29 14:44:21 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int nbr;

	nbr = 0;
	sign = 1;
	while (ft_whitespace((char)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (((*str) > 47) && ((*str) < 58))
	{
		nbr = nbr * 10 + (*str) - 48;
		str++;
	}
	return (nbr * sign);
}
