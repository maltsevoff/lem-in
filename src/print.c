/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:42:22 by omaltsev          #+#    #+#             */
/*   Updated: 2019/05/15 20:42:25 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		in_list_end(t_list **lst, char *str)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = (t_list *)ft_memalloc(sizeof(t_list));
		(*lst)->content = str;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_list *)ft_memalloc(sizeof(t_list));
		tmp->next->content = str;
	}
}

void		print_list(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr(lst->content);
		ft_putstr("\n");
		lst = lst->next;
	}
}

void		free_list(t_list **lst)
{
	t_list		*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void		show_ways(t_way *way)
{
	int		i;

	while (way != NULL)
	{
		i = 0;
		while (i < way->length)
		{
			ft_putstr("[");
			ft_putstr(way->room[i]->nm);
			ft_putstr("] ");
			i++;
		}
		ft_putstr("\n");
		way = way->next;
	}
}

void		input_ants(t_lem *farm)
{
	char	*line;

	while (get_next_line(g_fd, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			ft_error("Invalid ants number.\n");
		else if (ft_strncmp(line, "#", 1) == 0)
			in_list_end(&farm->list, line);
		else
		{
			farm->ants = valid_ants(line);
			in_list_end(&farm->list, line);
			break ;
		}
	}
	if (farm->ants == 0)
		ft_error("Invalid ants number.\n");
}
