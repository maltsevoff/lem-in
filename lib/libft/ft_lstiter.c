/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:38:06 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/10 16:42:14 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst != NULL)
	{
		while (lst != NULL)
		{
			tmp = lst->next;
			f(lst);
			lst = tmp;
		}
	}
}
