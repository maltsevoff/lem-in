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

void		read_room(char *line, t_lem *farm)
{
	t_room		*room;
	char		**map;

	room = add_last_room(farm->rooms);
	map = ft_strsplit(line, ' ');
	room->nm = ft_strdup(map[0]);
	room->coor->x = ft_atoi(map[1]);
	room->coor->y = ft_atoi(map[2]);
	free_map(map);
}

void		command_start_end(char *line, t_lem *farm, char *position)
{
	t_room	*room;
	char	**map;

	ft_strdel(line);
	line = get_next_line(FD, &line);
	map = ft_strsplit(line, ' ');
	position = ft_strdup(map[0]);
	read_room(line, farm);
	free_map(map);
}

int			valid_size(char *line)
{
	int			res;
	char		**map;

	map = ft_strsplit(line, ' ');
	if (map_len(map) == 3)
		res = 1;
	else
		res = 0;
	free_map(map);
	ft_strdel(&line);
	return (res);
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
	link = add_last_link(tmp_room->link);
	link->rm = find_room(farm->rooms, name2);
	tmp_room = find_room(farm->rooms, name2);
	link = add_last_link(tmp_room->link);
	link->rm = find_room(farm->rooms, name1);
}

void		read_links(char *line, t_lem *farm)
{
	set_link(line, farm);
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
	{
		set_link(line, farm);
		ft_strdel(&line);
	}
}

int			input_data(t_lem *farm)
{
	char		*line;

	get_next_line(FD, &line);
	farm->ants = ft_atoi(line);
	ft_strdel(&line);
	while (get_next_line(FD, &line) > 0)
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

void		show_farm(t_lem *farm)
{

}

int			main(void)
{
	t_lem	farm;

	if (input_data(&farm) == 0)
		return (0);
	show_farm(&farm);
	return (0);
}
