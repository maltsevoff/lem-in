/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:17:11 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/02 16:30:24 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			i++;
			ft_memcpy(dst, src, i);
			return (&dst[i]);
		}
		i++;
	}
	ft_memcpy(dst, src, i);
	return (NULL);
}
