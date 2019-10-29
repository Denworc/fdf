/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:55:43 by smaksymy          #+#    #+#             */
/*   Updated: 2016/12/02 16:38:04 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *newlist;
	t_list *new;
	t_list *newtmp;

	newlist = NULL;
	if (lst && f)
	{
		tmp = lst;
		if (!(newlist = ft_lstnew(f(tmp)->content, f(tmp)->content_size)))
			return (NULL);
		tmp = tmp->next;
		newtmp = newlist;
		while (tmp)
		{
			if (!(new = ft_lstnew(f(tmp)->content, f(tmp)->content_size)))
				return (NULL);
			newtmp->next = new;
			newtmp = new;
			tmp = tmp->next;
		}
	}
	return (newlist);
}
