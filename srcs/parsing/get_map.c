/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:12:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/08/30 22:45:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	count_line(char *path)
{
	int		fd;
	char	*line;
	int		size;

	size = -1;
	line = "";
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		size++;
	}
	close(fd);
	return (size);
}

static char	**put_map_in_array(char *path, char **map, int size)
{
	int		fd;
	int		i;
	
	i = -1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (++i < size)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	return (map);
}

char	**get_map(char *path)
{
	char	**map;
	
	map = ft_malloc(sizeof(char *) * (count_line(path) + 1));
	if (!map)
		return (NULL);
	if (!put_map_in_array(path, map, count_line(path)))
		return (NULL);
	return (map);
}
