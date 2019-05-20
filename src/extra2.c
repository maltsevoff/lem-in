/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:16:46 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/20 14:16:48 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_size(char *line)
{
	int			res;
	char		**map;

	map = ft_strsplit(line, ' ');
	if (map_len(map) == 3)
		res = 1;
	else
		res = 0;
	free_map(map);
	return (res);
}

int		map_len(char **map)
{
	int		i;

	i = 0;
	if (map == NULL)
		return (i);
	while (map[i])
		i++;
	return (i);
}

void	check_non_valid(t_lem *farm, char *error_info)
{
	t_room		*start;
	t_room		*end;

	start = find_room(farm->rooms, farm->start);
	end = find_room(farm->rooms, farm->end);
	find_ways(farm, start, end);
	if (!farm->way)
		ft_error(error_info);
	else
	{
		print_list(farm->list);
		free_list(&farm->list);
		send_insects(farm, start, end);
	}
	exit(0);
}

void	check_hash(char *str, t_lem *farm)
{
	char		**map;

	map = ft_strsplit(str, ' ');
	if (map_len(map) == 3)
	{
		free_map(map);
		valid_room(str);
	}
	else if (ft_strcmp(str, "##start") == 0 || ft_strcmp(str, "##end") == 0)
		ft_error("Too many start/end commands.\n");
	else
		in_list_end(&farm->list, str);
	free_map(map);
}

int		valid_coord(t_room *room, t_lem *farm)
{
	t_room	*tmp;

	tmp = farm->rooms;
	while (tmp)
	{
		if (room->coor->x == tmp->coor->x && room->coor->y == tmp->coor->y &&
			room != tmp)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
