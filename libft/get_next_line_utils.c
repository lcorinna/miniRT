/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:26:19 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 15:21:09 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *r)
{
	size_t	i;

	i = 0;
	if (r == NULL)
		return (i);
	while (r[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char	*a;
	char	i;

	i = (char) c;
	a = (char *) s;
	while (*a)
	{
		if (*a == i)
			return (a);
		a++;
	}
	if (*a == i)
		return (a);
	return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;
	int		count;

	i = 0;
	count = ft_strlen_gnl(s) - start;
	if (count > (int) len)
		count = (int) len;
	if (count <= 0)
		count = 0;
	newstr = (char *) malloc(sizeof(char) * (count + 1));
	if (newstr == NULL)
		return (newstr);
	while (s[start] != 0 && len-- != 0 && count != 0)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		p;
	char	*join;

	p = 0;
	i = 0;
	join = (char *) malloc(sizeof(char) * (ft_strlen_gnl(s1) + \
	ft_strlen_gnl(s2) + 1));
	if (join == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i])
			join[p++] = s1[i++];
		free(s1);
		s1 = NULL;
	}
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
			join[p++] = s2[i++];
	}
	join[p] = '\0';
	return (join);
}

char	*ft_free_res(char *res, int *chit)
{
	*chit = 1;
	free(res);
	res = NULL;
	return (NULL);
}
