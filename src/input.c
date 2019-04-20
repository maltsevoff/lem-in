/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:13:15 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/20 14:13:18 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_room(char *line, t_lem *farm)
{
	t_room		*room;
	char		**map;

	room = add_last_room(farm);
	map = ft_strsplit(line, ' ');
	room->coor = (t_coord *)ft_memalloc(sizeof(t_coord));
	room->nm = ft_strdup(map[0]);
	room->coor->x = ft_atoi(map[1]);
	room->coor->y = ft_atoi(map[2]);
	free_map(map);
}

void		command_start_end(char *line, t_lem *farm, char *position)
{
	char	**map;

	ft_strdel(&line);
	get_next_line(g_fd, &line);
	map = ft_strsplit(line, ' ');
	position = ft_strdup(map[0]);
	read_room(line, farm);
	free_map(map);
}

void		set_link(char *line, t_lem *farm)
{
	char		*name1;
	char		*name2;
	t_room		*tmp_room;
	t_link		*link;

	name1 = ft_strndup(line, ft_strchr(line, '-') - line);
	name2 = ft_strdup(ft_strchr(line, '-') + 1);
	tmp_room = find_room(farm->rooms, name1);
	link = add_last_link(tmp_room);
	link->rm = find_room(farm->rooms, name2);
	tmp_room = find_room(farm->rooms, name2);
	link = add_last_link(tmp_room);
	link->rm = find_room(farm->rooms, name1);
}

void		read_links(char *line, t_lem *farm)
{
	set_link(line, farm);
	ft_strdel(&line);
	while (get_next_line(g_fd, &line) > 0)
	{
		set_link(line, farm);
		ft_strdel(&line);
	}
}

int			input_data(t_lem *farm)
{
	char		*line;

	get_next_line(g_fd, &line);
	farm->ants = ft_atoi(line);
	ft_strdel(&line);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0)
			command_start_end(line, farm, farm->start);
		else if (ft_strcmp(line, "##end") == 0)
			command_start_end(line, farm, farm->end);
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_strdel(&line);
		else
		{
			if (valid_size(line) == 0)
				break;
			else
				read_room(line, farm);
		}
	}
	read_links(line, farm);
	return (1);
}
