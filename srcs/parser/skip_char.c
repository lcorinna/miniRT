/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:37:35 by ayajirob          #+#    #+#             */
/*   Updated: 2022/08/09 21:11:13 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	ft_skip_visible_char_munis(char *str, int i)
{
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') || \
	(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || \
	str[i] == '.' || str[i] == ',' || str[i] == '-')
		i++;
	return (i);
}

int	ft_skip_visible_char(char *str, int i)
{
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') || \
	(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || \
	str[i] == '.' || str[i] == ',' )
		i++;
	return (i);
}

int	ft_skip_invisible_char(char *str, int i)
{
	while (str[i] != '\0' && (str[i] == 32) || (str[i] > 8 && str[i] < 14))
		i++;
	return (i);
}

int	ft_search_next_value(char *str, int i, int flag)
{
	if (flag == 1)
	{
		i = ft_skip_invisible_char(str, i);
		i = ft_skip_visible_char(str, i);
		i = ft_skip_invisible_char(str, i);
	}
	else if (flag == 2)
	{
		i = ft_skip_visible_char_munis(str, i);
		i = ft_skip_invisible_char(str, i);
	}
	return (i);
}

int	ft_check_dir(t_vec3 dir)
{
	if (dir.x < -1.0 || dir.x > 1.0 || dir.y < -1.0 || dir.y > 1.0 || \
													dir.z < -1.0 || dir.z > 1.0)
		return (1);
	if (dir.x == 0 && dir.y == 0 && dir.z == 0)
		return (1);
	return (0);
}
