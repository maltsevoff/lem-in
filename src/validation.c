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

void		valid_room(char *str)
{
	int		i;
	int		tmp;

	i = 0;
	if (str == NULL || str[i] == '\0' || str[i] == 'L' || str[i] == '#')
		ft_error("invalid room\n");
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] != ' ')
		ft_error("invalid room\n");
	i++;
	while (str[i] && str[i] != ' ' && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != ' ')
		ft_error("invalid room\n");
	tmp = ++i;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != '\0' || tmp == i)
		ft_error("invalid room\n");
}

void		valid_link(char *str)
{
	int		i;
	int		tmp;

	i = 0;
	if (str == NULL || str[i] == '\0')
		ft_error("ivalid link\n");
	tmp = i;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i] != '-' || tmp == i)
		ft_error("ivalid link\n");
	tmp = ++i;
	while (str[i])
		i++;
	if (tmp == i)
		ft_error("ivalid link\n");
}
