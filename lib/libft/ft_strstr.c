/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:03:16 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/02 18:35:15 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test_word(const char *haystack, const char *needle, size_t pos)
{
	size_t		i;

	i = 0;
	while (haystack[pos] == needle[i] && haystack[pos] && needle[i])
	{
		pos++;
		i++;
	}
	if (i == ft_strlen(needle))
		return (1);
	else
		return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if ((*needle == '\0' && haystack == '\0') || needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		if (test_word(haystack, needle, i) == 1)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
