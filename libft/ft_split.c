/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:24:42 by lcorinna          #+#    #+#             */
/*   Updated: 2021/11/14 13:14:38 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean_memory(char **array, int i)
{
	while (i > -1)
	{
		free (array[i]);
		array [i] = NULL;
		i--;
	}
	free (array);
	array = NULL;
	return (NULL);
}

static char	**ft_mem_for_array(char const *s, char c)
{
	char	**array;
	int		i;
	int		m;

	m = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			m++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	array = (char **) malloc((m + 1) * sizeof(char *));
	if (m == 0)
		array[0] = NULL;
	return (array);
}

static char	**ft_write_array(char **array, char *s, char c)
{
	int	j;
	int	m;

	j = 0;
	m = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
			{
				s++;
				j++;
			}
			array[m] = ft_substr(s - j, 0, j);
			if (array[m] == NULL)
				return (ft_clean_memory(array, m));
			m++;
			s--;
			j = 0;
		}
		s++;
	}
	array[m] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**array;

	str = (char *) s;
	array = ft_mem_for_array(s, c);
	if (array == NULL)
		return (array);
	array = ft_write_array(array, str, c);
	return (array);
}
