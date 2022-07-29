/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/07/29 16:08:36 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_check_file(t_main *data, char *f_name)
{
	int		i;

	i = 0;
	while (f_name[i] != '\0')
	{
		if (f_name[i] == '.')
			if (ft_strncmp(f_name + i, ".rt", 4))
				ft_exit("The file must have the extension \".rt\"\n", 1);
		i++;
	}
	data->fd = open(f_name, O_RDONLY);
	if (data->fd == -1)
		ft_exit("Mistake \"open\"", 2);
	data->n_wndw = f_name;
}

int	ft_count_lines(t_main *data)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (str == NULL)
			break ;
		free(str);
		++i;
	}
	if (i == 0)
		ft_exit("Empty file\n", 1);
	return (i);
}

void	ft_writing_array(t_main *data, int count, char *f_name)
{
	int		i;

	i = 0;
	data->maps = malloc(sizeof(char *) * (count + 1));
	if (!data->maps)
		ft_exit("Memory was not allocated\n", 1);
	close(data->fd);
	data->fd = open(f_name, O_RDONLY);
	while (count != 0)
	{
		data->maps[i] = get_next_line(data->fd);
		// printf("data->maps[%d] - %s\n", i, data->maps[i]); //del
		if (data->maps[i] == NULL)
			ft_exit("Memory was not allocated\n", 1);
		i++;
		count--;
	}
	data->maps[i] = NULL;
}

void	ft_read_file(t_main *data, char *f_name)
{
	int		count;

	count = ft_count_lines(data);
	ft_writing_array(data, count, f_name);
}

void	ft_type_selection(t_main *data, char *type, char *str)
{
	if (type[0] == '\0')
		return ;
	else if (ft_strncmp(type, "A", 1) == 0)
		printf("AMBIANT\n"); //del
	else if (ft_strncmp(type, "C", 1) == 0)
		printf("CAMERA\n"); //del
	else if (ft_strncmp(type, "L", 1) == 0)
		printf("LIGHT\n"); //del
	else if (ft_strncmp(type, "pl", 3) == 0)
		printf("PLANE\n"); //del
	else if (ft_strncmp(type, "sp", 3) == 0)
		printf("SPHERE\n"); //del
	else if (ft_strncmp(type, "cy", 3) == 0)
		printf("CYLINDER\n"); //del
	else
	{
		ft_putstr_fd(type, 2);
		ft_putstr_fd(": has an unidentified type\n", 2);
	}
}

void	ft_which_element(t_main *data, char *str)
{
	int		i;
	int		j;
	char	type[3];

	i = 0;
	while (str[i] != '\0' && (str[i] == 32) || (str[i] > 8 && str[i] < 14))
		i++;
	j = 0;
	while (str[i] != '\0' && j != 2)
	{
		type[j] = '\0';
		type[j] = str[i];
		i++;
		j++;
	}
	type[j] = '\0';
	ft_type_selection(data, type, str);
}

void	ft_writing_scene(t_main *data)
{
	int		i;

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
