/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:26:55 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/25 17:26:57 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_links(t_lem *farm)
{
	t_room		*tmp_room;
	int			child;
	int			parent;
	t_link		*tmp_link;

	child = 0;
	parent = 0;
	tmp_room = farm->rooms;
	while (tmp_room != NULL)
	{
		tmp_link = tmp_room->link;
		while (tmp_link != NULL)
		{
			if (tmp_link->rm->level < tmp_room->level)
				parent++;
			else if (tmp_link->rm->level > tmp_room->level)
				child++;
			else

		}
	}
}
