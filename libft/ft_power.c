/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:50:19 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/05 17:07:31 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int n, unsigned int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	if (n == 0)
		return (0);
	while (power > 0)
	{
		result *= n;
		power--;
	}
	return (result);
}
