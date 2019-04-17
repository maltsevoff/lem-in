/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:18:54 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/11 18:38:32 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	if (dst < src)
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (tmp);
}
