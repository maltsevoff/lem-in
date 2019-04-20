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

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_link
{
	struct s_room	*rm;
	struct s_link	*next;
}				t_link;

typedef struct	s_room
{
	char			*nm;
	t_coord			*coor;
	t_link			*link;
	struct s_room	*next;
}				t_room;

typedef struct	s_lem
{
	t_room	*rooms;
	char	*start;
	char	*end;
	int		ants;
}				t_lem;

int				g_fd;

int				input_data(t_lem *farm);
int				map_len(char **map);
int				valid_size(char *line);
t_room			*add_last_room(t_lem *farm);
void			free_map(char **map);
char			*ft_strndup(const char *s1, int num);
t_room			*find_room(t_room *root, char *name);
t_link			*add_last_link(t_room *room);
void			valid_room(char *str);
void			ft_error(char *error_info);
void			valid_link(char *str);

#endif
