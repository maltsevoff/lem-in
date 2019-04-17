/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:38:34 by omaltsev          #+#    #+#             */
/*   Updated: 2018/10/30 10:55:51 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	let;
	char	*tmp;

	tmp = (char *)s;
	let = c;
	size = ft_strlen(tmp);
	if (let == '\0')
		return (&tmp[size]);
	while (size >= 0)
	{
		if (tmp[size] == let)
			return (&tmp[size]);
		size--;
	}
	return (NULL);
}
