/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/20 20:06:26 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	if (argc != 2)
		ft_exit("Check the number of arguments\n");
	ft_parser(argc, argv, &data);
	// printf("HERE\n"); //del
	// ft_calibration(&data, data.scene, data.scene->cam);
	if (ft_initialization(&data, data.scene))
		ft_program_completion(&data, "", 1);
	ft_draw(&data, data.scene);
	mlx_loop(&data.mlx->mlx);
	return (0);
}
