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
	int				level;
	int				fl;
	struct s_room	*way;
}				t_room;

typedef struct	s_way
{
	t_room			**room;
	int				length;
	struct s_way	*next;
}				t_way;

typedef struct	s_lem
{
	t_room	*rooms;
	char	*start;
	char	*end;
	t_link	*queue;
	int		ants;
	t_way	*way;
	t_list	*list;
}				t_lem;

int				g_fd;

void			input_data(t_lem *farm);
int				map_len(char **map);
int				valid_size(char *line);
t_room			*add_last_room(t_lem *farm);
void			free_map(char **map);
char			*ft_strndup(const char *s1, int num);
t_room			*find_room(t_room *root, char *name);
t_link			*add_last_link(t_room *room);
void			valid_room(char *str);
void			ft_error(char *error_info);
void			valid_link(char *str, t_lem *farm);
int				algorithm(t_lem *farm, t_room *end, t_room *room);
int				valid_connect_links(t_link *link, t_room *room1,
					t_room *room2, t_lem *farm);
void			find_ways(t_lem *farm, t_room *start, t_room *end);
int				bfs(t_lem *farm, t_room *end, t_room *room);
void			send_insects(t_lem *farm, t_room *start, t_room *end);
void			check_non_valid(t_lem *farm, char *error_info);
int				valid_ants(char *str);
void			check_hash(char *str, t_lem *farm);
int				valid_coord(t_room *room, t_lem *farm);
void			input_ants(t_lem *farm);

void			show_ways(t_way *way);
void			in_list_end(t_list **lst, char *str);
void			print_list(t_list *lst);
void			free_list(t_list **lst);

#endif
