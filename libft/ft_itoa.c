/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:09:33 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/13 19:18:01 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero_chek(long long a)
{
	char	*count;

	count = (char *) malloc((a + 2) * sizeof(char));
	if (count == NULL)
		return (NULL);
	count[0] = '0';
	count[1] = '\0';
	return (count);
}

static int	ft_intlen(long long i)
{
	int	size;

	size = 0;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*count;
	long long	number;

	number = (long long) n;
	n = 0;
	if (number == 0)
		return (ft_zero_chek(number));
	if (number < 0)
	{
		number *= -1;
		n += 1;
	}
	n += ft_intlen(number) + 1;
	count = (char *) malloc((n) * sizeof(char));
	if (count == NULL)
		return (count);
	count[--n] = '\0';
	while (number > 0)
	{
		count[--n] = 48 + number % 10;
		number /= 10;
	}
	if (n == 1)
		count[--n] = '-';
	return (count);
}
