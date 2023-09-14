

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
			data->mapy_size++;
	}
	data->mapy_size++;
	close(fd);
	get_map2(av, data);
	return (0);
}

void	get_map2(char *av, t_data *data)
{
	int i;
	int fd;

	i = -1;
	data -> map = malloc(sizeof(char *) * data->mapy_size + 1);
	data -> map[data->mapy_size] = NULL;
	fd = open(av, O_RDONLY, 0777);
	data->map[++i] = get_next_line(fd);
	if (data->map[i] == NULL)
	{
		printf("Map Is Empty\n");
		exit(0);
	}
	
	while (++i < data->mapy_size)
		data -> map[i] = get_next_line(fd);
	close(fd);
}
