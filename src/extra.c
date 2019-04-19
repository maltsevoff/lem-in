/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:01:49 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/18 15:01:51 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			map_len(char **map)
{
	int		i;

	i = 0;
	if (map == NULL)
		return (i);
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	if (map[i] == NULL)
		return ;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

t_room		*add_last_room(t_room *root)
{
	t_room		*room;

	if (root == NULL)
	{
		root = (t_room *)ft_memalloc(sizeof(t_room));
		return (root);
	}
	else
	{
		while (root->next != NULL)
			root = root->next;
		room = (t_room *)ft_memalloc(sizeof(t_room));
		root->next = room;
		return (room);
	}
}

char		*ft_strndup(const char *s1, int num)
{
	int		i;
	char	*res;

	i = ft_strlen(s1);
	res = (char*)malloc(sizeof(char) * (num + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < num)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_room		*find_room(t_room *root, char *name)
{
	if (root == NULL)
		return (NULL);
	while (ft_strcmp(root->nm, name) != 0)
	{
		if (root->next == NULL)
			return (NULL);
		root = root->next;
	}
	return (root);
}

t_link		*add_last_link(t_link *root)
{
	t_link		*link;

	if (root == NULL)
	{
		root = (t_link *)ft_memalloc(sizeof(t_link));
		return (root);
	}
	else
	{
		while (root->next != NULL)
			root = root->next;
		link = (t_link *)ft_memalloc(sizeof(t_link));
		root->next = link;
		return (link);
	}
}
