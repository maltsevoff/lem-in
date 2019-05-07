/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:48:06 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/06 16:48:08 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_from_con(t_room *target, t_room *room)
{
	t_link		*link;
	t_link		*tmp;

	link = room->link;
	if (room->link != NULL && room->link->rm == target)
	{
		tmp = room->link->next;
		free(room->link);
		room->link = tmp;
	}
	else
	{
		while (link->next != NULL && link->next->rm != target)
			link = link->next;
		tmp = link->next->next;
		free(link->next);
		link->next = tmp;
	}
}

void		delete_links(t_room *current)
{
	t_link		*tmp;

	while (current->link != NULL)
	{
		delete_from_con(current, current->link->rm);
		tmp = current->link->next;
		free(current->link);
		current->link = tmp;
	}
}

void		save_delete(t_way *way, t_room *end, t_room *start)
{
	int			i;
	t_room		*current;

	i = end->level - 1;
	way->room = (t_room **)ft_memalloc(sizeof(t_room *) * end->level);
	current = end;
	while (current != NULL && i >= 0)
	{
		printf("tt: %s %d\n", current->nm, end->level);
		way->room[i] = current;
		if (current != start && current != end)
			delete_links(current);
		i--;
		current = current->way;
	}
	int		j = 0;
	printf("way1: ");
	while (j < end->level)
	{
		printf("%s ", way->room[j]->nm);
		j++;
	}
	printf("\n");
}

void		save_way(t_lem *farm, t_room *end, t_room *start)
{
	t_way	*tmp_way;

	tmp_way = farm->way;
	if (tmp_way != NULL)
	{
		while (tmp_way->next != NULL)
			tmp_way = tmp_way->next;
		tmp_way->next = (t_way *)ft_memalloc(sizeof(t_way));
		tmp_way = tmp_way->next;
	}
	else
	{
		farm->way = (t_way *)ft_memalloc(sizeof(t_way));
		tmp_way = farm->way;
	}
	save_delete(tmp_way, end, start);
}

void		find_ways(t_lem *farm)
{
	t_room		*end;
	t_room		*start;
	t_room		*tmp_room;
	t_link		*tmp_queue;

	start = find_room(farm->rooms, farm->start);
	end = find_room(farm->rooms, farm->end);
	while (algorithm(farm, end, start))
	{
		save_way(farm, end, start);
		tmp_room = farm->rooms;
		while (tmp_room != NULL)
		{
			tmp_room->fl = 0;
			tmp_room = tmp_room->next;
		}
		tmp_queue = farm->queue;
		while (farm->queue != NULL)
		{
			tmp_queue = tmp_queue->next;
			free(farm->queue);
			farm->queue = tmp_queue;
		}
		show_farm(farm);
	}
}
