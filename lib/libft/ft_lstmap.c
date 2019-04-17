/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:42:24 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/10 17:08:36 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	fresh = f(lst);
	tmp = fresh;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (fresh);
}
