/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:51 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/08 17:46:53 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		send_insects(t_lem *farm)
{
	int		ants;
	int		tmp_ants;
	t_way	*way;

	tmp_ants = 0;
	ants = farm->ants;
	while (ants > 0)
	{
		while (way != NULL)
		{
			if (ants > tmp_ants)
			way = way->next;
		}
	}
}
