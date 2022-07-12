/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/12 19:21:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	main(int argc, char **argv)
{
	t_main	data;

	data = (t_main){};
	ft_parser(argc, argv, &data);
	// printf("HERE\n"); //del
	// ft_calibration(&data, data.scene, data.scene->cam);
	if (ft_initialization(&data, data.scene))
		ft_program_completion(&data, "", 1);
	ft_draw(&data, data.scene);
	return (0);
}
