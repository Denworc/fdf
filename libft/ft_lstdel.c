/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:52:06 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/02 15:31:56 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next;

	if (alst && *alst && del)
	{
		lst = *alst;
		while (lst)
		{
			next = lst->next;
			ft_lstdelone(&lst, del);
			lst = next;
		}
		*alst = NULL;
	}
}
