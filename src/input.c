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
	int			i;
	t_room		*room;
	t_room		*tmp_rm;
	char		**map;

	valid_room(line);
	room = add_last_room(farm);
	map = ft_strsplit(line, ' ');
	room->coor = (t_coord *)ft_memalloc(sizeof(t_coord));
	room->nm = ft_strdup(map[0]);
	tmp_rm = farm->rooms;
	while (tmp_rm)
		if (tmp_rm != room && ft_strcmp(tmp_rm->nm, room->nm) == 0)
			ft_error("Same room name.\n");
		else
			tmp_rm = tmp_rm->next;
	i = -1;
	while (room->nm[++i])
		if (room->nm[i] == '-')
			ft_error("Using '-' in room name is forbidden.\n");
	room->coor->x = ft_atoi(map[1]);
	room->coor->y = ft_atoi(map[2]);
	if (valid_coord(room, farm) == 0)
		ft_error("Same coordinates\n");
	free_map(map);
}

void		command_start_end(char *line, t_lem *farm, char **position, int fl)
{
	char	**map;

	if ((farm->start != NULL && fl == 1) || (farm->end != NULL && fl == 2))
		ft_error("Too many start/end commands.\n");
	in_list_end(&farm->list, line);
	while (get_next_line(g_fd, &line) > 0 && *line)
	{
		if (ft_strncmp(line, "#", 1) == 0)
			check_hash(line, farm);
		else
		{
			map = ft_strsplit(line, ' ');
			*position = ft_strdup(map[0]);
			read_room(line, farm);
			free_map(map);
			in_list_end(&farm->list, line);
			break ;
		}
	}
}

void		set_link(char *line, t_lem *farm)
{
	char		*name1;
	char		*name2;
	t_room		*tmp_room;
	t_link		*link;

	valid_link(line, farm);
	name1 = ft_strndup(line, ft_strchr(line, '-') - line);
	name2 = ft_strdup(ft_strchr(line, '-') + 1);
	if ((tmp_room = find_room(farm->rooms, name1)) == NULL)
		check_non_valid(farm, "Linked room doesn't exist\n");
	link = add_last_link(tmp_room);
	if (valid_connect_links(link, tmp_room,
			find_room(farm->rooms, name2), farm) == 0)
		check_non_valid(farm, "Linked room doesn't exist\n");
	tmp_room = find_room(farm->rooms, name2);
	link = add_last_link(tmp_room);
	valid_connect_links(link, tmp_room, find_room(farm->rooms, name1), farm);
	ft_strdel(&name1);
	ft_strdel(&name2);
}

void		read_links(char *line, t_lem *farm)
{
	if (farm->start == NULL || farm->end == NULL)
		ft_error("Doesn't exist start/end.\n");
	set_link(line, farm);
	in_list_end(&farm->list, line);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (*line != '#')
			set_link(line, farm);
		in_list_end(&farm->list, line);
	}
}

void		input_data(t_lem *farm)
{
	char		*line;

	input_ants(farm);
	while (get_next_line(g_fd, &line) > 0)
		if (ft_strcmp(line, "##start") == 0)
			command_start_end(line, farm, &farm->start, 1);
		else if (ft_strcmp(line, "##end") == 0)
			command_start_end(line, farm, &farm->end, 2);
		else if (ft_strncmp(line, "#", 1) == 0)
			check_hash(line, farm);
		else
		{
			if (valid_size(line) == 0)
				break ;
			else
			{
				read_room(line, farm);
				in_list_end(&farm->list, line);
			}
		}
	read_links(line, farm);
}
