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

void		save_way(t_lem *farm, t_room *end)
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
		farm->way = (t_way *)ft_memalloc(sizeof(t_way));
}

void		find_ways(t_lem *farm)
{
	t_room		*end;
	t_room		*start;

	start = find_room(farm->rooms, farm->start);
	end = find_room(farm->rooms, farm->end);
	while (algorithm(farm, end, start))
	{
		save_way(farm, end);
	}
}
