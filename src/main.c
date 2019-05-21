/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:41:10 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/20 13:21:34 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		zero_flags(t_lem *farm)
{
	t_room		*room;

	room = farm->rooms;
	while (room != NULL)
	{
		room->fl = 0;
		room = room->next;
	}
}

void		ft_bonus(t_lem *farm, int steps)
{
	ft_putstr("STEPS: ");
	ft_putnbr(--steps);
	ft_putstr("\n");
	show_ways(farm->way);
}

int			main(int argc, char **argv)
{
	t_room	*start;
	t_room	*end;
	t_lem	*farm;

	g_fd = 0;
	farm = (t_lem *)ft_memalloc(sizeof(t_lem));
	if (argc == 2 && ft_strcmp(argv[1], "--bonus") == 0)
		farm->bonus = 1;
	input_data(farm);
	start = find_room(farm->rooms, farm->start);
	end = find_room(farm->rooms, farm->end);
	find_ways(farm, start, end);
	if (!farm->way)
		ft_error("No ways\n");
	print_list(farm->list);
	free_list(&farm->list);
	send_insects(farm, start, end);
	return (0);
}
