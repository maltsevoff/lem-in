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

void		show_queue(t_link *queue)
{
	while (queue != NULL)
	{
		printf("[%s] ", queue->rm->nm);
		queue = queue->next;
	}
	printf("\n");
}

void		in_queue_end(t_link *queue, t_link *link)
{
	t_link		*elem;

	while (queue->next != NULL)
		queue = queue->next;
	elem = (t_link *)ft_memalloc(sizeof(t_link));
	queue->next = elem;
	elem->rm = link->rm;
}

void		set_start_queue(t_room *start, t_lem *farm)
{
	t_link		*room_link;

	room_link = start->link;
	start->fl = 1;
	farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
	farm->queue->rm = room_link->rm;
	room_link->rm->fl = 1;
	room_link->rm->way = start;
	room_link = room_link->next;
	while (room_link != NULL)
	{
		in_queue_end(farm->queue, room_link);
		room_link->rm->fl = 1;
		room_link->rm->way = start;
		room_link = room_link->next;
	}
}

t_room		*add_in_queue(t_room *root_rm, t_lem *farm)
{
	t_link		*link;

	link = root_rm->link;
	printf("root: %s\n", root_rm->nm);
	show_queue(farm->queue);
	while (link != NULL)
	{
		if (link->rm->fl == 0)
		{
			in_queue_end(farm->queue, link);
			link->rm->way = root_rm;
			link->rm->fl = 1;
		}
		link = link->next;
	}
	return (farm->queue->rm);
}

void		back_way(t_room *end, char *start)
{
	printf("way: ");
	while (ft_strcmp(end->nm, start) != 0)
	{
		printf("%s-", end->nm);
		end = end->way;
	}
	printf("%s\n", end->nm);
}

int			algorithm(t_lem *farm, t_room *end, t_room *room)
{
	t_link		*tmp_queue;

	printf("tut: %p | ", farm->queue);
	set_start_queue(room, farm);
	show_queue(farm->queue);
	room = farm->queue->rm;
	while (farm->queue != NULL)
	{
		room->fl = 1;
		tmp_queue = farm->queue->next;
		free(farm->queue);
		farm->queue = tmp_queue;
		if (room != end)
		{
			room = add_in_queue(room, farm);
			// show_queue(farm->queue);
		}
		else
			return (1);
	}
	back_way(room, farm->start);
	return (0);
}
