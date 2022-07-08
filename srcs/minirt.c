/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/07 18:09:18 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_program_completion(t_main *data, char *error, int flag)
{
	// ft_clear_arr_struct(data, 0); чистим всю память
	data = NULL; //заглушка
	if (flag)
		perror(error);
	exit (flag);
}

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	ft_parser(argc, argv, &data);
	// printf("HERE\n"); //del
	ft_calibration(&data, data.scene, data.scene->cam);
	if (ft_initialization(&data))
		ft_program_completion(&data, "", 1);
	ft_draw(&data, data.scene);
	return (0);
}
