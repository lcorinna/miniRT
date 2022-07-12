/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:23 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:17:16 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_number(char *done)
{
	long long	res;
	int			i;

	i = 0;
	res = 0;
	while (done[i] > 47 && done[i] < 58)
	{
		res = res * 10 + (done[i] - 48);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45)
		res = (ft_number((char *) &str[++i]) * (-1));
	else if (str[i] == 43)
		res = (ft_number((char *) &str[++i]));
	else
		res = (ft_number((char *) &str[i]));
	return (res);
}
