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

int			count_tmp(t_way *way, t_way *list)
{
	int			res;
	static int	flag = 0;

	if (flag == 0)
	{
		flag = 1;
		return (0);
	}
	res = 0;
	while (list != way)
	{
		res += (way->length - 1) - (list->length - 1);
		list = list->next;
	}
	return (res);
}

void		show_turn(int ant_num, char *room_name)
{
	ft_putstr("L");
	ft_putnbr(ant_num);
	ft_putstr("-");
	ft_putstr(room_name);
	ft_putstr(" ");
}

void		move_ants(t_way *way, t_room *start, t_room *end, int *flag)
{
	int		i;

	i = way->length - 1;
	while (way->room[i - 1] != start)
	{
		if (way->room[i - 1]->fl > 0)
		{
			way->room[i]->fl = way->room[i - 1]->fl;
			way->room[i - 1]->fl = 0;
		}
		if (way->room[i]->fl > 0 && (*flag = 1))
			show_turn(way->room[i]->fl, way->room[i]->nm);
		if (way->room[i] == end)
			way->room[i]->fl = 0;
		i--;
	}
}

void		check_way(t_lem *farm, t_way *way, int *flag, int *ants)
{
	if (farm->ants > count_tmp(way, farm->way) && farm->ants > 0 && ++(*flag))
	{
		way->room[1]->fl = *ants;
		show_turn(way->room[1]->fl, way->room[1]->nm);
		(*ants)++;
		farm->ants--;
	}
}

void		send_insects(t_lem *farm, t_room *start, t_room *end)
{
	int		flag;
	int		string;
	int		ants;
	t_way	*way;

	flag = 1;
	string = 0;
	ants = 1;
	one_way(farm, farm->way, start);
	while (flag)
	{
		flag = 0;
		way = farm->way;
		ft_putstr("\n");
		string++;
		while (way != NULL)
		{
			move_ants(way, start, end, &flag);
			check_way(farm, way, &flag, &ants);
			way = way->next;
		}
	}
	if (farm->bonus)
		ft_bonus(farm, string);
}
