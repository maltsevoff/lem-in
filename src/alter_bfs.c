/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:33:48 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/15 20:33:50 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		in_queue_end(t_lem *farm, t_room *room)
{
	t_link		*tmp_queue;

	if (farm->queue != NULL)
	{
		tmp_queue = farm->queue;
		while (tmp_queue->next != NULL)
			tmp_queue = tmp_queue->next;
		tmp_queue->next = (t_link *)ft_memalloc(sizeof(t_link));
		tmp_queue->next->rm = room;
	}
	else
	{
		farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
		farm->queue->rm = room;
	}
	room->fl = 1;
}

void		work_room(t_room *room, t_lem *farm)
{
	t_link		*link;
	t_link		*tmp_queue;

	link = room->link;
	tmp_queue = farm->queue;
	while (link != NULL)
	{
		if (link->rm && link->rm->fl == 0)
		{
			link->rm->way = room;
			link->rm->level = room->level + 1;
			in_queue_end(farm, link->rm);
		}
		link = link->next;
	}
}

void		show_queue(t_link *queue)
{
	while (queue != NULL)
	{
		printf("[%s] ", queue->rm->nm);
		queue = queue->next;
	}
	printf("\n");
}

int			bfs(t_lem *farm, t_room *end, t_room *start)
{
	t_link		*tmp_queue;

	start->level = 1;
	start->fl = 1;
	farm->queue = (t_link *)ft_memalloc(sizeof(t_link));
	farm->queue->rm = start;
	while (farm->queue && farm->queue->rm != end)
	{
		work_room(farm->queue->rm, farm);
		tmp_queue = farm->queue;
		farm->queue = farm->queue->next;
		free(tmp_queue);
		tmp_queue = NULL;
	}
	return (end->way == NULL ? 0 : 1);
}
