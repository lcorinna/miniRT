/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:37:35 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/03 17:46:26 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	ft_skip_visible_char_munis(char *str, int i)
{
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') || \
	(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || \
	str[i] == '.' || str[i] == ',' || str[i] == '-')
	// {
		// printf("visible = str[%d] - %c\n", i , str[i]); //del
		// sleep(1);
		i++;
	// }
	return (i);
}

int	ft_skip_visible_char(char *str, int i)
{
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') || \
	(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || \
	str[i] == '.' || str[i] == ',' )
	// {
		// printf("visible = str[%d] - %c\n", i , str[i]); //del
		// sleep(1);
		i++;
	// }
	return (i);
}

int	ft_skip_invisible_char(char *str, int i)
{
	while (str[i] != '\0' && (str[i] == 32) || (str[i] > 8 && str[i] < 14))
	// {
	// 	printf("invisible = str[%d] - %c\n", i , str[i]); //del
		// sleep(1);
		i++;
	// }
	return (i);
}

int	ft_search_next_value(char *str, int i, int flag)
{
	if (flag == 1)
	{
		i = ft_skip_invisible_char(str, i); //если есть пробел до знач, то пропускаю
		i = ft_skip_visible_char(str, i); //пропускаю тип
		i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	}
	else if (flag == 2)
	{
		i = ft_skip_visible_char_munis(str, i); //пропускаю тип
		i = ft_skip_invisible_char(str, i); //пропускаю пробелы до след значения
	}
	return (i);
}

int	ft_check_dir(t_vec3 dir)
{
	if (dir.x < -1.0 || dir.x > 1.0 || dir.y < -1.0 || dir.y > 1.0 || \
													dir.z < -1.0 || dir.z > 1.0)
		return (1);
	return (0);
}
