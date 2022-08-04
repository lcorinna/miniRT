/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_completion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:20:48 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/04 20:48:23 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_exit(t_main *data, char *str, int flag)
{
	if (data->scene.sh != NULL)
	{
		while (data->scene.sh)
		{
			free(data->scene.sh);
			data->scene.sh = data->scene.sh->next;
		}
	}
	if (flag > 1)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	if (flag > 0)
		flag = 1;
	exit (flag);
}
