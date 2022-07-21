/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/21 18:31:54 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	// if (argc != 2)
	// 	ft_exit("Check the number of arguments\n", 1);
	ft_parser(argc, argv, &data);
	printf("%f\n", data.scene.amb.clr.x); //del
	printf("%f\n", data.scene.sh.pos.x); //del
	// printf("HERE\n"); //del
	// ft_calibration(&data, data.scene, data.scene->cam);
	ft_initialization(&data);
	ft_draw_loop(&data, &data.scene, &data.mlx);
	mlx_loop(&data.mlx.mlx);
	return (0);
}
