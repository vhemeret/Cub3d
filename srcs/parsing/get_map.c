/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:12:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/16 16:51:39 by vahemere         ###   ########.fr       */
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

static char	*put_map_in_array(char *map, char *line)
{
	int	i;

	i = 0;
	printf("%s", line); // -> sans \n affcihe pas la derniere ligne (ligne qui va etre copier)
	printf("%s\n", line); // -> avec \n affcihe pas la derniere ligne
	while (line[i])
		i++;
	map = malloc(sizeof(char) * (i + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (line[++i])
		map[i] = line[i];
	map[i] = '\0';
	return (map);
}

char	**get_map(char *path)
{
	char	**map;
	char	*line;
	int		size;
	int		fd;
	int		i;

	size = count_line(path);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (size)
	{
		line = get_next_line(fd);
		map[++i] = put_map_in_array(*map, line);
		free(line);
		line = NULL;
		size--;
	}
	map[i + 1] = NULL;
	i = -1;
	// while (map[++i])
		// printf("%s", map[i]);
	close(fd);
	return (NULL);
}
