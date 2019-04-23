/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:16:12 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/23 13:16:14 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		in_queue_end(t_link *queue, t_link *link)
{
	t_link		*elem;

	while (queue->next != NULL)
		queue = queue->next;
	elem = (t_link *)ft_memalloc(sizeof(t_link));
	queue->next = elem;
	elem->next = NULL;
	elem->rm = link->rm;
}

t_link		*add_in_queue(t_room *root_rm, t_lem *farm)
{
	t_link		*link;

	link = root_rm->link;
	while (link != NULL)
	{
		if (link->rm->fl == 0)
			if (farm->queue == NULL)
			{
				farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
				farm->queue->rm = root_rm;
				farm->queue->next = NULL;
			}
			else
				in_queue_end(farm->queue, link);
		link->rm->fl = 1;
		link = link->next;
	}

}

void		algorithm(t_lem *farm)
{
	t_room		*room;
	t_link		*que_el;

	room = find_room(farm->rooms, farm->start);
	while (ft_strcmp(room->nm, farm->end) != 0)
	{
		room->fl = 1;
		que_el = add_in_queue(room, farm);
	}
}
