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

int			input_data(t_lem *farm)
{
	char		*line;

	while (get_next_line(FD, &line) > 0)
	{
		if (ft_strncmp(line, "##", 2))
		{
			check_command(line);
		}
		else
	}
}

int			main(void)
{
	t_lem	farm;

	if (input_data(&farm) = 0)
		return (0);
	return (0);
}
