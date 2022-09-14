/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:51 by brhajji-          #+#    #+#             */
/*   Updated: 2022/09/13 17:00:39 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	get_nb_lines()
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open("/mnt/nfs/homes/brhajji-/Desktop/Cub3d/map/test.cub", O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

char	**init_map()
{
	char	**map;
	int		i;
	int		fd;
	int		size;

	i = 0;
	size = get_nb_lines();
	map = malloc(sizeof(char *) * (size + 1));
	fd = open("/mnt/nfs/homes/brhajji-/Desktop/Cub3d/map/test.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("test");	
		return (NULL);
	}
	while (i <= size)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}

void	init(t_data_engine	**engine)
{
	(*engine) = malloc(sizeof(t_data_engine));
	(*engine)->img = malloc(sizeof(t_data_img));
	(*engine)->init = malloc(sizeof(t_init));
	(*engine)->map = malloc(sizeof(t_map));
	(*engine)->tmp = malloc(sizeof(t_data_img));
	(*engine)->player = malloc(sizeof(t_player));
	(*engine)->player->vue_x = 1920 / 2;
	(*engine)->player->vue_y = 540;
	(*engine)->player->x = 1;
	(*engine)->player->y = 2;
	(*engine)->player->vec_x = -1;
	(*engine)->player->vec_y = 0;
	(*engine)->map->line = get_nb_lines();
	(*engine)->map->map = init_map();
	(*engine)->map->column = ft_strlen((*engine)->map->map[0]);
	(*engine)->map->column -= 1;
}