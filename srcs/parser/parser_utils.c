/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:53:39 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 19:12:05 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	ft_data_entry_error(char *str, t_shapes *shape, int flag)
{
	if (flag)
	{
		if (shape != NULL)
			free(shape);
	}
	ft_putstr_fd("Check the line for the correct input\n", 2);
	ft_putstr_fd(str, 2);
}

void	ft_writing_array(t_main *data, int count, char *f_name)
{
	int		i;

	i = 0;
	data->maps = malloc(sizeof(char *) * (count + 1));
	if (!data->maps)
		ft_exit(data, "Memory was not allocated\n", 1);
	close(data->fd);
	data->fd = open(f_name, O_RDONLY);
	while (count != 0)
	{
		data->maps[i] = get_next_line(data->fd);
		if (data->maps[i] == NULL)
			ft_exit(data, "Memory was not allocated\n", 1);
		i++;
		count--;
	}
	data->maps[i] = NULL;
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
		ft_exit(data, "Empty file\n", 1);
	return (i);
}

void	ft_read_file(t_main *data, char *f_name)
{
	int		count;

	count = ft_count_lines(data);
	ft_writing_array(data, count, f_name);
}

void	ft_check_file(t_main *data, char *f_name)
{
	int		i;

	i = 0;
	while (f_name[i] != '\0')
	{
		if (f_name[i] == '.')
			if (ft_strncmp(f_name + i, ".rt", 4))
				ft_exit(data, "The file must have the extension \".rt\"\n", 1);
		i++;
	}
	data->fd = open(f_name, O_RDONLY);
	if (data->fd == -1)
		ft_exit(data, "Mistake \"open\"", 2);
	data->n_wndw = f_name;
}
