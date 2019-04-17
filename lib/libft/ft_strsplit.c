/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:02:46 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/12 16:17:42 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] != c && str[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	return (words);
}

static char	*make_word(char const *str, char c)
{
	int		size;
	int		i;
	char	*res;

	i = 0;
	size = 0;
	while (str[size] != c && str[size])
		size++;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		res[i] = *str;
		str++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**make_make(char const *s, char c, int words)
{
	int		i;
	char	**res;

	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!(res[i] = make_word(&(*s), c)))
				return (NULL);
			while (*s != c && *s)
				s++;
			while (*s == c && *s)
				s++;
			i++;
		}
		else
			s++;
	}
	res[words] = NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s || !c)
		return (NULL);
	words = count_words(s, c);
	res = make_make(s, c, words);
	return (res);
}
