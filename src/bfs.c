/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:16:42 by yhliboch          #+#    #+#             */
/*   Updated: 2019/04/22 13:16:43 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	check_old_link(t_lem *lem, char *line)
// {
// 	t_node	*nd;
// 	t_lst	*link;

// 	nd = lem->node;
// 	while (nd && ft_strncmp(line, nd->room->name,
// 			ft_strlen(nd->room->name)))
// 		nd = nd->next;
// 	link = nd->link;
// 	while (link)
// 	{
// 		if (ft_strcmp(line + ft_strlen(nd->room->name)
// 							+ 1, link->room->name) == 0)
// 			error("error\n");
// 		link = link->next;
// 	}
// }

void	init_turn(t_lem *lem, t_room *start)
{
	t_link	*del_queue;
	t_room	*tmp_rooms;

	tmp_rooms = lem->rooms;
	while (lem->queue)
	{
		del_queue = lem->queue;
		lem->queue = lem->queue->next;
		free(del_queue);
		del_queue = NULL;
	}
	while (tmp_rooms)
	{
		tmp_rooms->fl = 0;
		tmp_rooms->way = NULL;
		tmp_rooms = tmp_rooms->next;
	}
	start->fl = 1;
	start->level = 1;
	lem->queue = ft_memalloc(sizeof(t_lem));
	lem->queue->rm = start;
	lem->queue->next = NULL;
}

void	add_rooms(t_room *tmp_rooms, t_link *turn, t_link *tmp_link)
{
	t_link	*tmp_turn;

	tmp_turn = turn;
	while (tmp_link)
	{
		if (tmp_link->rm->fl == 0)
		{
			tmp_link->rm->fl = 1;
			tmp_link->rm->level = tmp_rooms->level + 1;
			tmp_link->rm->way = tmp_rooms;
			while (tmp_turn->next != NULL)
				tmp_turn = tmp_turn->next;
			tmp_turn->next = ft_memalloc(sizeof(t_link));
			tmp_turn->next->rm = tmp_link->rm;
			tmp_turn->next->next = NULL;
		}
		tmp_link = tmp_link->next;
	}
}

int		bfs_yasya(t_lem *lem, t_room *end, t_room *start)
{
	t_room	*tmp_rooms;
	// t_link	*tmp_link;
	t_link	*del_queue;

	// init_turn(lem, start);
	start->fl = 1;
	start->level = 1;
	lem->queue = ft_memalloc(sizeof(t_lem));
	lem->queue->rm = start;
	lem->queue->next = NULL;
	while (lem->queue && lem->queue->rm != end)
	{
		tmp_rooms = lem->rooms;
		// while (tmp_rooms && tmp_rooms != lem->queue->rm)
			// tmp_rooms = tmp_rooms->next;
		// tmp_link = lem->queue->rm->link;
		add_rooms(lem->queue->rm, lem->queue, lem->queue->rm->link);
		del_queue = lem->queue;
		lem->queue = lem->queue->next;
		free(del_queue);
		del_queue = NULL;
	}
	return (end->way == NULL ? 0 : 1);
}
