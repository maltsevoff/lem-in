/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:56:18 by omaltsev          #+#    #+#             */
/*   Updated: 2018/11/07 13:18:40 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int						i;
	unsigned long int		res;
	int						flag;

	res = 0;
	i = 0;
	flag = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = 0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res >= 9223372036854775807 && flag == 1)
			return (-1);
		else if (res > 9223372036854775807 && flag == 0)
			return (0);
		i++;
	}
	return (flag ? res : -res);
}
