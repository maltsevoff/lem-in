/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:01:49 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/18 15:01:51 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			map_len(char **map)
{
	int		i;

	i = 0;
	if (map == NULL)
		return (i);
	while (map[i])
		i++;
	return (i);
}

t_room		*add_last_room(t_room *root)
{
	t_room		*room;

	if (root == NULL)
	{
		root = (t_room *)ft_memalloc(sizeof(t_room));
		return (root);
	}
	else
	{
		while (root->next != NULL)
			root = root->next;
		room = (t_room *)ft_memalloc(sizeof(t_room));
		root->next = room;
		return (room);
	}

}
