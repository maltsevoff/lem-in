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

void		in_queue_end(t_lem *farm, t_link *link)
{
	t_link		*elem;

	if (farm->queue != NULL)
	{
		while (farm->queue->next != NULL)
			farm->queue = farm->queue->next;
		elem = (t_link *)ft_memalloc(sizeof(t_link));
		farm->queue->next = elem;
		elem->rm = link->rm;
	}
	else
	{
		farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
		farm->queue->rm = link->rm;
	}
}

int			set_start_queue(t_room *start, t_lem *farm)
{
	t_link		*room_link;

	room_link = start->link;
	if (room_link == NULL)
		return (0);
	start->fl = 1;
	start->level = 1;
	farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
	farm->queue->rm = room_link->rm;
	room_link->rm->fl = 1;
	room_link->rm->level = start->level + 1;
	room_link->rm->way = start;
	room_link = room_link->next;
	while (room_link != NULL)
	{
		in_queue_end(farm, room_link);
		room_link->rm->fl = 1;
		room_link->rm->level = start->level + 1;
		room_link->rm->way = start;
		room_link = room_link->next;
	}
	return (1);
}

void		add_in_queue(t_room *root_rm, t_lem *farm)
{
	t_link		*link;

	link = root_rm->link;
	// printf("root: %s\n", root_rm->nm);
	// show_queue(farm->queue);
	while (link != NULL)
	{
		if (link->rm->fl == 0)
		{
			in_queue_end(farm, link);
			link->rm->way = root_rm;
			link->rm->fl = 1;
			// printf("root: %s r_lvl: %d\n", root_rm->nm, root_rm->level);
			link->rm->level = root_rm->level + 1;
		}
		link = link->next;
	}
}

t_room		*first_from_queue(t_lem *farm)
{
	t_link		*tmp_queue;
	t_room		*room;

	if (farm->queue == NULL)
		return (NULL);
	room = farm->queue->rm;
	tmp_queue = farm->queue->next;
	free(farm->queue);
	farm->queue = tmp_queue;
	return (room);
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
	printf("start-------------------\n");
	// printf("tut: %p | \n", farm->queue);
	if (set_start_queue(room, farm) == 0)
		return (0);
	// show_queue(farm->queue);
	room = first_from_queue(farm);
	while (farm->queue != NULL || room != NULL)
	{
		room->fl = 1;
		show_queue(farm->queue);
		if (room != end)
		{
			// printf("room: %s\n", room->nm);
			// show_queue(farm->queue);
			add_in_queue(room, farm);
			room = first_from_queue(farm);
		}
		else
		{
			printf("tut\n");
			back_way(room, farm->start);
			return (1);
		}
	}
	return (0);
}
