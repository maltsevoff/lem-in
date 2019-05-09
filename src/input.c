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
	char		**map;

	valid_room(line);
	room = add_last_room(farm);
	map = ft_strsplit(line, ' ');
	// printf("%s %p\n", line, line);
	room->coor = (t_coord *)ft_memalloc(sizeof(t_coord));
	room->nm = ft_strdup(map[0]);
	i = -1;
	while (room->nm[++i])
		if (room->nm[i] == '-')
			ft_error("using '-' in room name is forbidden\n");
	room->coor->x = ft_atoi(map[1]);
	room->coor->y = ft_atoi(map[2]);
	free_map(map);
}

void		command_start_end(char *line, t_lem *farm, char **position)
{
	char	**map;

	free(line);
	get_next_line(g_fd, &line);
	map = ft_strsplit(line, ' ');
	*position = ft_strdup(map[0]);
	read_room(line, farm);
	free_map(map);
	free(line);
}

void		set_link(char *line, t_lem *farm)
{
	char		*name1;
	char		*name2;
	t_room		*tmp_room;
	t_link		*link;

	valid_link(line);
	name1 = ft_strndup(line, ft_strchr(line, '-') - line);
	name2 = ft_strdup(ft_strchr(line, '-') + 1);
	if ((tmp_room = find_room(farm->rooms, name1)) == NULL)
		ft_error("room doesn't exist\n");
	link = add_last_link(tmp_room);
	if (valid_connect_links(link, tmp_room,
			find_room(farm->rooms, name2)) == 0)
		ft_error("room doesn't exist\n");
	tmp_room = find_room(farm->rooms, name2);
	link = add_last_link(tmp_room);
	valid_connect_links(link, tmp_room, find_room(farm->rooms, name1));
	ft_strdel(&name1);
	ft_strdel(&name2);
}

void		read_links(char *line, t_lem *farm)
{
	set_link(line, farm);
	ft_strdel(&line);
	while (get_next_line(g_fd, &line) > 0)
	{
		set_link(line, farm);
		free(line);
	}
}

void		input_data(t_lem *farm)
{
	char		*line;

	get_next_line(g_fd, &line);
	farm->ants = ft_atoi(line);
	ft_strdel(&line);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0)
			command_start_end(line, farm, &farm->start);
		else if (ft_strcmp(line, "##end") == 0)
			command_start_end(line, farm, &farm->end);
		else if (ft_strncmp(line, "#", 1) == 0)
			ft_strdel(&line);
		else
		{
			if (valid_size(line) == 0)
				break ;
			else
			{
				read_room(line, farm);
				free(line);
			}
		}
	}
	read_links(line, farm);
}
