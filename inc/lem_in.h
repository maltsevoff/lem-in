/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:43:19 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/17 15:43:21 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define FD 0

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_link
{
	t_list	*rm;
	t_link	*next;
}				t_link;

typedef struct	s_room
{
	char	*nm;
	t_coord	*coor;
	t_list	*link;
	t_room	*next;
}				t_room;

typedef struct	s_lem
{
	t_room	*rooms;
	char	*start;
	char	*end;
	int		ants;
}				t_lem;

int				map_len(char **map);

#endif
