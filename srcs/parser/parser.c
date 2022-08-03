/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/03 23:02:18 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_type_selection(t_main *data, char *type, char *str)
{
	if (type[0] == '\0')
		return ;
	else if (ft_strncmp("A", type, 2) == 0)
		ft_ambiant(data, type, str);
	else if (ft_strncmp("C", type, 2) == 0)
		ft_camera(data, type, str);
	else if (ft_strncmp("L", type, 2) == 0)
		ft_light(data, str);
	else if (ft_strncmp("pl", type, 3) == 0)
		ft_plane(data, str);
	else if (ft_strncmp("sp", type, 3) == 0)
		ft_sphere(data, str);
	else if (ft_strncmp("cy", type, 3) == 0)
		ft_cylinder(data, str, 0);
	else
	{
		ft_putstr_fd(type, 2);
		ft_putstr_fd(": has an unidentified type\n", 2);
	}
	if (data->scene.sh != NULL)
	{
		printf("data - %d\n", data->scene.sh->type); //del
		printf("data - %f\n", data->scene.sh->pos.x); //del
		printf("data - %p\n", data->scene.sh); //del
	}
}

void	ft_which_element(t_main *data, char *str)
{
	int		i;
	int		j;
	int		size;
	char	*type;

	i = 0;
	j = 0;
	size = 0;
	i = ft_skip_invisible_char(str, i); //если есть пробел до знач, то пропускаю
	size = ft_skip_visible_char(str, i); //считаю тип
	printf("\n\n"); //del
	// printf("str - %s\n", str); //del
	printf("size - %d\n", size); //del
	type = malloc(sizeof(char) * (size + 1));
	if (!type)
		ft_exit("Memory was not allocated\n", 1);
	while (str[i] != '\0' && j != size)
	{
		type[j] = '\0';
		type[j] = str[i];
		i++;
		j++;
	}
	type[j] = '\0';
	ft_type_selection(data, type, str);
	free(type);
}

void	ft_writing_scene(t_main *data)
{
	int		i;

	data->scene = (t_scene){};
	i = 0;
	while (data->maps[i])
	{
		ft_which_element(data, data->maps[i]);
		i++;
	}
}

void	ft_clean_maps(t_main *data)
{
	int	i;

	i = 0;
	if (data->maps)
	{
		while (data->maps[i])
		{
			free(data->maps[i]);
			i++;
		}
		free(data->maps);
	}
}

int	ft_parser(int argc, char **argv, t_main *data)
{
	ft_check_file(data, argv[1]);
	ft_read_file(data, argv[1]);
	ft_writing_scene(data);
	ft_clean_maps(data);
	return (0);
}

/*
проверка на одну камеру, один свет
проверка координат, чтобы не было запятых после значения
*/


// int	ft_parser(int argc, char **argv, t_main *data)
// {
// 	t_ambient	amb;
// 	t_vec3		clr_amb;

// 	t_light		lght;
// 	t_vec3		lght_pos;
// 	t_vec3		lght_clr;

// 	t_camera	cam;
// 	t_vec3		cam_origin;
// 	t_vec3		cam_direction;

// 	t_shapes	sphere;
// 	t_vec3		sphere_center;
// 	t_vec3		sphere_color;

// 	clr_amb = ft_new_vec3(255, 255, 255);
// 	amb = ft_new_amb(0.5, &clr_amb); //добавляю общий свет

// 	cam_origin = ft_new_vec3(0, 0, 0);
// 	cam_direction = ft_new_vec3(0, 0, -1);
// 	cam = ft_new_camera(&cam_origin, &cam_direction, 70); //добавляю камеру

// 	lght_pos = ft_new_vec3(-200, 200, 300);
// 	lght_clr = ft_new_vec3(255, 255, 255);
// 	lght = ft_new_light(&lght_pos, 0.9, &lght_clr); //делаю точечный свет

// 	sphere_center = ft_new_vec3(50, 50, -50);
// 	sphere_color = ft_new_vec3(255, 0, 0);
// 	sphere = ft_new_sphere(&sphere_center, &sphere_color, 40); //делаю сферу

// 	data->scene = ft_new_scene(&amb, &cam, &lght, &sphere); //добавляю все в структуру сцена
// 	argc = 0; //del
// 	argv = NULL; //del
// 	return (0);
// }
