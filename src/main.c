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

int			read_links(char *line, t_lem *farm)
{
}

void		command_start_end(char *line, t_lem *farm, char *position)
{
	t_room	*room;
	char	**map;

	ft_strdel(line);
	line = get_next_line(FD, &line);
	map = ft_strsplit(line, ' ');
	position = ft_strdup(map[0]);
	room = add_last_room(farm->rooms);
	room->nm = ft_strdup(map[0]);
}

int			input_data(t_lem *farm)
{
	char		*line;
	char		**map;

	get_next_line(FD, &line);
	farm->ants = ft_atoi(line);
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
	{
		if (ft_strcmp(line, "##start"))
			command_start_end(line, farm, farm->start);
		else if (ft_strcmp(line, "##end"))
			command_start_end(line, farm, farm->end);
		else if (ft_strncmp(line, "#", 1))
			ft_strdel(&line);
		else
		{
			map = ft_strsplit(line, ' ');
			if (map_len(map) != 3)
			{
				read_links(line, farm);
				break;
			}
			else
				read_rooms(line, farm);
		}
	}
}

int			main(void)
{
	t_lem	farm;

	if (input_data(&farm) == 0)
		return (0);
	return (0);
}
