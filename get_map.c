/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:53:53 by bguzel            #+#    #+#             */
/*   Updated: 2023/09/25 21:46:49 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map(char *av, t_data *data)
{
	int		fd;
	int		i;
	char	a;

	i = 0;
	fd = open(av, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("THERE IS NO SUCH FILE");
		return (1);
	}
	while (read(fd, &a, 1))
	{
		if (a == '\n')
			data->cub_size++;
	}
	data->cub_size++;
	close(fd);
	get_map2(av, data);
	return (0);
}

void	get_map2(char *av, t_data *data)
{
	int		i;
	int		fd;

	i = -1;
	fd = open(av, O_RDONLY, 0777);
	while (++i < data->cub_size - 1)
	{
		data->flager = 0;
		data->image_path = get_next_line(fd);
		if (data -> image_path[0] != '\n' && data -> image_path[1] != '\0')
		{
			while (data->image_path[data->flager] == ' ')
				data->flager++;
			path_helper(data->image_path[data->flager], data->image_path[data->flager + 1], data);
		}
		free(data->image_path);
		if (data->arg_count == 6)
			break ;
	}
	get_map_helper_2(data, fd);
}
