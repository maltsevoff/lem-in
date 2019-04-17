/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:45:25 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/11 15:12:14 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(unsigned int n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

static char		*write_num(unsigned int n, int flag, int size)
{
	int		rozm;
	char	*res;

	rozm = size + flag;
	if (!(res = (char *)malloc(sizeof(char) * (rozm + 1))))
		return (NULL);
	if (flag == 1)
		res[0] = '-';
	res[rozm--] = '\0';
	while (size > 0)
	{
		res[rozm] = n % 10 + 48;
		n /= 10;
		rozm--;
		size--;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	int				size;
	int				flag;
	unsigned int	num;
	char			*res;

	flag = 0;
	if (n < 0)
	{
		num = n * -1;
		flag = 1;
	}
	else
		num = n;
	size = num_size(num);
	if (!(res = write_num(num, flag, size)))
		return (NULL);
	return (res);
}
