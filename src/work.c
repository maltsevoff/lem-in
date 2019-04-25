/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:33:20 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/25 10:33:22 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_level_queue(t_room *start, t_lem *farm)
{
	t_link		*room_link;

	room_link = start->link;
	start->fl = 1;
	farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
	farm->queue->rm = room_link->rm;
	room_link->rm->fl = 1;
	room_link->rm->level = start->level + 1;
	room_link = room_link->next;
	while (room_link != NULL)
	{
		in_queue_end(farm->queue, room_link);
		room_link->rm->fl = 1;
		room_link->rm->level = start->level + 1;
		room_link = room_link->next;
	}
}

t_room		*level_queue(t_room *root_rm, t_lem *farm)
{
	t_link		*link;

	link = root_rm->link;
	while (link != NULL)
	{
		if (link->rm->fl == 0)
		{
			in_queue_end(farm->queue, link);
			link->rm->fl = 1;
			link->rm->level = root_rm->level + 1;
		}
		link = link->next;
	}
	return (farm->queue->rm);
}

void		set_levels(t_lem *farm)
{
	t_room		*room;
	t_link		*tmp_queue;

	room = find_room(farm->rooms, farm->start);
	set_level_queue(room, farm);
	room = farm->queue->rm;
	while (ft_strcmp(room->nm, farm->end) != 0)
	{
		room->fl = 1;
		// room->level = lvl;
		tmp_queue = farm->queue->next;
		free(farm->queue);
		farm->queue = tmp_queue;
		room = level_queue(room, farm);
	}
	// back_way(room, farm->start);
}

void		work(t_lem *farm)
{
	t_room		*start;
	t_room		*end;
	t_link		*tmp_queue;

	end = find_room(farm->rooms, farm->end);
	start = find_room(farm->rooms, farm->start);
	set_levels(farm);
	while (farm->queue != NULL)
	{
		tmp_queue = farm->queue->next;
		free(farm->queue);
		farm->queue = tmp_queue;
	}
}
