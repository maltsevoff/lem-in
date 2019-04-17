/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:41:07 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/21 12:40:02 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*check_list(int fd, t_list *lst, int ret)
{
	t_list		*prev;

	while (lst != NULL)
	{
		if (lst->content_size == (size_t)fd)
		{
			if (ret == 0 && (lst->content == NULL ||
						((char *)lst->content)[0] == '\0'))
				return (NULL);
			return (lst);
		}
		prev = lst;
		lst = lst->next;
	}
	lst = ft_lstnew("", fd);
	prev->next = lst;
	return (lst);
}

t_list	*make_line(char *buf, int fd, t_list *lst, int ret)
{
	char		*temp;

	temp = lst->content;
	lst->content = ft_strjoin((char *)lst->content, buf);
	ft_strdel(&temp);
	while (ft_strchr(buf, '\n') == NULL && ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		temp = lst->content;
		lst->content = ft_strjoin((char *)lst->content, buf);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	return (lst);
}

int		general_work(t_list *lst, char **line)
{
	char		*temp;

	if (ft_strchr(lst->content, '\n'))
	{
		*line = ft_strnew(ft_strchr(lst->content, '\n') - (char *)lst->content);
		*line = ft_strncpy(*line, lst->content, ft_strchr(lst->content, '\n')
				- (char *)lst->content);
		temp = lst->content;
		lst->content = ft_strdup(lst->content + (ft_strlen(*line) + 1));
		ft_strdel(&temp);
		return (1);
	}
	else
	{
		*line = ft_strdup(lst->content);
		ft_memdel(&lst->content);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buf;
	t_list			*lst;
	static t_list	*root;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (BUFF_SIZE < 1 || fd < 0 || ret < 0)
	{
		free(buf);
		return (-1);
	}
	if (root == NULL)
	{
		root = ft_lstnew("", fd);
		lst = root;
	}
	else if ((lst = check_list(fd, root, ret)) == NULL)
		return (0);
	lst = make_line(buf, fd, lst, ret);
	return (general_work(lst, line));
}
