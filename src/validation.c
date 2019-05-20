/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:18:39 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/20 17:18:42 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_error(char *error_info)
{
	ft_putstr(error_info);
	exit(0);
}

int			valid_ants(char *str)
{
	int			i;
	int			number;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Invalid ants number.\n");
	}
	number = ft_atoi(str);
	if (number <= 0)
		ft_error("Invalid ants number.\n");
	return (number);
}

int			valid_connect_links(t_link *link, t_room *room1,
									t_room *room2, t_lem *farm)
{
	t_link		*all_link;

	if (room1 == NULL || room2 == NULL)
		return (0);
	all_link = room1->link;
	while (all_link != NULL)
	{
		if (all_link->rm == room2)
			check_non_valid(farm, "Same link.\n");
		all_link = all_link->next;
	}
	link->rm = room2;
	return (1);
}

void		valid_room(char *str)
{
	int		i;
	int		tmp;

	i = 0;
	if (str == NULL || str[i] == '\0' || str[i] == 'L' || str[i] == '#')
		ft_error("invalid room\n");
	tmp = i;
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] != ' ' || tmp == i)
		ft_error("invalid room\n");
	tmp = ++i;
	while (str[i] && str[i] != ' ' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != ' ' || tmp == i)
		ft_error("invalid room\n");
	tmp = ++i;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != '\0' || tmp == i)
		ft_error("invalid room\n");
}

void		valid_link(char *str, t_lem *farm)
{
	int		i;
	int		count;
	char	**map;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '-')
			count++;
	if (count != 1)
		check_non_valid(farm, "Invalid link\n");
	map = ft_strsplit(str, '-');
	if (map_len(map) != 2)
		check_non_valid(farm, "Invalid link\n");
	i = -1;
	if (!map[0] || !map[1])
		check_non_valid(farm, "Invalid link\n");
	free_map(map);
	i = -1;
}
