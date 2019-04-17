/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:38:21 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/05 19:17:22 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dsize;
	size_t	ssize;

	i = 0;
	j = 0;
	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	if (dstsize <= dsize)
		return (dstsize + ssize);
	while (dst[i] && (dstsize - 1))
		i++;
	while ((dstsize - 1) > i && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dsize + ssize);
}
