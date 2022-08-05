/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/05 19:01:37 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_type_selection(t_main *data, char *type, char *str)
{
	ft_check_repetitions(data, str, type);
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
		// sleep (10); //del
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
	type = malloc(sizeof(char) * (size + 1));
	if (!type)
		ft_exit(data, "Memory was not allocated\n", 1);
	while (str[i] != '\0' && j != size)
	{
		type[j] = str[i];
		i++;
		j++;
		type[j] = '\0';
	}
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
	if (data->scene.amb.flag == 0 || data->scene.cam.flag == 0 || \
												data->scene.lght.flag == 0)
		ft_exit(data, "An unfinished scene! \
Check the types \"C\", \"A\", \"L\" and try again\n", 1);
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
	printf("\n\n"); //del
	return (0);
}
