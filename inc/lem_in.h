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

typedef struct	s_room
{
	char	*nm;
	int		x;
	int		y;
	t_list	*link;
}				t_room;

typedef struct	s_lem
{
	t_room	*room;
	char	*start;
	char	*end;
}				t_lem;


#endif
