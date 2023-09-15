

#include "cub3d.h"

int	get_map(char *av, t_data *data)
{
    int	fd;
	int	i;
	char	a;

	i = 0;
	fd = open(av, O_RDONLY, 0777);
	if(fd == -1)
	{
		printf("THERE IS NO SUCH FILE");
		return (1);
	}
	while (read(fd, &a, 1))
	{
		if(a == '\n')
			data->cub_size++;
	}
	data->cub_size++;
	close(fd);
	get_map2(av, data);
	return (0);
}

void	get_map2(char *av, t_data *data)
{
	int	i;
	int	fd;
	int	ret;
	int	j;

	i = 0;
	j = 0;
	data -> map = malloc(sizeof(char *) * data->mapy_size + 1);
	data -> map[data->mapy_size] = NULL;
	fd = open(av, O_RDONLY, 0777);

	while(i < data->cub_size - 1)
	{	
		
		data->image_path = get_next_line(fd);
		if(data -> image_path[0] != '\n' && data -> image_path[1] != '\0')
			if ((ret = path_helper(data->image_path[0], data->image_path[1], data)))
				if (ret == 1)
				{
					printf("ERROR\n");
					exit(0);
				}
		free(data->image_path);
		i++;
		if (ret == 3)
			break;	
	}
	data->image_path = get_next_line(fd);
	free(data->image_path);
	while ((data -> map[j] = get_next_line(fd)))
	{
		data->mapy_size++;
		j++;
	}
	close(fd);
}
