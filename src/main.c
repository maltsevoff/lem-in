/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:41:10 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/17 15:41:13 by omaltsev         ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	t_room	*start;
	t_room	*end;
	t_lem	*farm;

	if (argc != 2)
		return (0);
	g_fd = open(argv[1], O_RDONLY);
	farm = (t_lem *)ft_memalloc(sizeof(t_lem));
	input_data(farm);
	start = find_room(farm->rooms, farm->start);
	end = find_room(farm->rooms, farm->end);
	print_list(farm->list);
	// delete_links(&farm);
	find_ways(farm, start, end);
	close(g_fd);
	free_list(&farm->list);
	send_insects(farm, start, end);
	// system("leaks lem-in > leaks");
	// printf("leak: %p\n", farm);
	return (0);
}
