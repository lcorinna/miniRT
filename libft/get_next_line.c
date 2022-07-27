/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:09:04 by lcorinna          #+#    #+#             */
/*   Updated: 2022/03/02 15:21:04 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_for_str(char *res)
{
	char	*str;
	int		i;

	i = 0;
	if (res == NULL)
		return (NULL);
	while (res[i] != '\n' && res[i] != '\0')
		i++;
	str = ft_substr_gnl(res, 0, i + 1);
	return (str);
}

char	*ft_trim_for_res(char *res)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (res == NULL)
		return (NULL);
	while (res[i] != '\n' && res[i] != '\0')
		i++;
	if (res[i] == '\0' || res[i + 1] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	while (res[i + j] != '\0')
		j++;
	str = ft_substr_gnl(res, (i + 1), j);
	free(res);
	res = NULL;
	return (str);
}

char	*ft_res_res(char *res, int i)
{
	if (i < 0)
	{
		res = NULL;
		return (NULL);
	}
	if (i == 0)
		return (res);
	return (res);
}

char	*ft_read(int fd, char *res, int *chit, int i)
{
	char	*str;

	while ((ft_strchr_gnl(res, '\n')) == NULL)
	{
		if (*chit != 1)
			res = ft_free_res(res, chit);
		str = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (str == NULL)
			return (NULL);
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0 || i == 0)
		{
			free(str);
			res = ft_res_res(res, i);
			return (res);
		}
		str[i] = '\0';
		res = ft_strjoin_gnl(res, str);
		free(str);
		if (i < BUFFER_SIZE)
			return (res);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*str;
	int			chit;
	int			i;

	i = 0;
	chit = 1;
	if (fd < 0)
		return (NULL);
	if (res == NULL)
	{
		res = (char *) malloc(sizeof(char) * chit);
		if (res == NULL)
			return (NULL);
		while (chit != -1)
			res[chit--] = '\0';
	}
	res = ft_read(fd, res, &chit, i);
	str = ft_trim_for_str(res);
	res = ft_trim_for_res(res);
	return (str);
}
