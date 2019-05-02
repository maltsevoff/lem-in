/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:26:55 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/25 17:26:57 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_connection(t_room *room1, t_room *room2)
{
	t_link		*links;

	links = room1->link;
	while (links->next != NULL && links->next->rm != room2)
		links = links->next;
	if (links->next == NULL)

}

void		delete_links(t_lem *farm)
{
	t_room		*tmp_room;
	int			child;
	int			parent;
	t_link		*tmp_link;

	child = 0;
	parent = 0;
	tmp_room = farm->rooms;
	while (tmp_room != NULL)
	{
		tmp_link = tmp_room->link;
		while (tmp_link != NULL)
		{
			if (tmp_link->rm->level < tmp_room->level)
				parent++;
			else if (tmp_link->rm->level > tmp_room->level)
				child++;
			else
				delete_connection(tmp_link->rm, tmp_room);
			tmp_link = tmp_link->next;
		}
	}
}
