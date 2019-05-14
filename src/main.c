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

void		show_farm(t_lem *farm)
{
	t_room	*room;
	t_link	*link;

	room = farm->rooms;
	printf("ants: %d\n", farm->ants);
	while (room != NULL)
	{
		printf("lvl: %d | %s |", room->level, room->nm);
		link = room->link;
		while (link != NULL)
		{
			printf(" %s", link->rm->nm);
			link = link->next;
		}
		printf("\n");
		room = room->next;
	}
}

int			main(int argc, char **argv)
{
	t_lem	*farm;

	if (argc != 2)
		return (0);
	g_fd = open(argv[1], O_RDONLY);
	farm = (t_lem *)ft_memalloc(sizeof(t_lem));
	input_data(farm);
	// print_list(farm->list);
	// show_farm(farm);
	// delete_links(&farm);
	find_ways(farm);
	close(g_fd);
	free_list(&farm->list);
	// system("leaks lem-in > leaks");
	// printf("leak: %p\n", farm);
	return (0);
}
