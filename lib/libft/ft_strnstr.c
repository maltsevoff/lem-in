/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:04:37 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/11 15:59:19 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return (&((char *)haystack)[0]);
	while (haystack[i] && i < len)
	{
		if ((haystack[i] == needle[0]) &&
				(ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
				&& (ft_strlen(needle) <= len - i))
		{
			return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
