/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:07:56 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/10 17:09:19 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void	const *content, size_t content_size)
{
	t_list		*root;

	if (!(root = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(root->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(root->content, content, content_size);
		root->content_size = content_size;
	}
	else
	{
		root->content = NULL;
		root->content_size = 0;
	}
	root->next = NULL;
	return (root);
}
