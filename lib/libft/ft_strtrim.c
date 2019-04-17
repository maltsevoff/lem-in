/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:15:25 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/11 18:20:22 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*res;
	size_t		i;
	size_t		end;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (res = ft_strnew(0));
	end = ft_strlen(s);
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	if (!(res = (char *)malloc(sizeof(char) * (end - i + 1))))
		return (NULL);
	res = ft_strncpy(res, &s[i], end - i);
	res[end - i] = '\0';
	return (res);
}
