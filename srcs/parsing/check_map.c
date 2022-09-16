/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/16 13:19:41 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	parsing_data_map(char **map, int *i, t_map *data)
{
	t_face	face;

	face.NO = 0;
	face.SO = 0;
	face.WE = 0;
	face.EA = 0;
	face.F = 0;
	face.C = 0;
	face.data = 0;
	*i = 0;
	while (map[*i] && face.data != 6)
	{
		if (map[*i][0] && map[*i][0] != '\n')
		{
			if (!check_data(&map[*i], face, data))
				return (0);
			face.data++;
		}
		(*i)++;
	}
	if (face.data != 6
		&& (face.NO != 1 || face.SO != 1 || face.WE != 1 || face.EA != 1)
		&& (face.F != 1 || face.C != 1))
		return (0);
	return (1);
}

// static int	check_first_and_last_line(char *line)
// {
// 	int		i;
// 	char	*line_clear;

// 	i = -1;
// 	line_clear = remove_wspace(line);
// 	if (line_clear)
// 	{
// 		while (line_clear[++i])
// 		{
// 			if (line_clear[i] != '1' && line_clear[i] != ' ')
// 			{
// 				printf("a\n");
// 				free(line_clear);
// 				return (0);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		free(line_clear);
// 		return (0);
// 	}
// 	free(line_clear);
// 	return (1);
// }

// static int	check_intermediate_line(char *line)
// {
// 	char	*line_clear;
// 	int		i;
// 	int		start;
// 	int		end;

// 	i = 0;
// 	line_clear = remove_wspace(line);
// 	if (line_clear)
// 	{
// 		if (line_clear[0] != '1')
// 		{
// 			free(line_clear);
// 			return (0);
// 		}
// 		while(line_clear[i + 1] != '\0')
// 			i++;
// 		if (line_clear[i] != '1')
// 		{
// 			free(line_clear);
// 			return (0);
// 		}
// 	}
// 	else
// 	{
// 		free(line_clear);
// 		return (0);
// 	}
// 	free(line_clear);
// 	i = -1;
// 	while (line[++i])
// 	{
// 		if (line[i] == ' ' || line[i] == '\t')
// 			continue ;
// 		else
// 			start = i - 1;
// 		if (line[i + 1] && line[i + 1] == '\0')
// 			end = i;
// 	}
// 	while (++start < end)
// 		if (line[start] == ' ')
// 			line[start] = '0';
// 	printf("%s", line);
// 	return (1);
// }

// static int	check_char_map(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while(map[++i])
// 	{
// 		j = -1;
// 		while(map[i][++j] && map[i][j] != '\n')
// 		{
// 			if (map[i][j] != '1' || map[i][j] != '0'
// 				|| map[i][j] != 'N' || map[i][j] != 'S'
// 				|| map[i][j] != 'E' || map[i][j] != 'w')
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

// static int	check_if_map_closed(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[++j])
// 		{
			
// 		}
// 	}
// }

// static char	*put_line(char *line)
// {
// 	int		i;
// 	char	*nw;

// 	i = 0;
// 	while (line[++i] && line[i] != '\n')
// 		i++;
// 	nw = malloc(sizeof(char) * (i + 1));
// 	if (!nw)
// 		return (NULL);
// 	i = -1;
// 	while (line[++i] && line[i] != '\n')
// 		nw[i] = line[i];
// 	if (line[i])
// 		nw[i] = '\n';
// 	else
// 		nw[i] = '\0';
// 	return (nw);
// }

static int	parsing_body_map(char **map, t_all *all)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	all->map->nb_line = i;
	all->map->map = malloc(sizeof(char *) * (all->map->nb_line + 1));
	if (!all->map->map)
		return (0);
	i = -1;
	while (map[++i])
	{
		printf("map[%i] = %s",i, map[i]);
		// all->map->map[i] = put_line(map[i]);
	}
	// all->map->map[i] = NULL;
	
	
	// i = -1;
	// while (all->map->map[++i])
	// 	printf("%i -> %s", i, map[i]);
	
	// while (map[++i])
	// {
	// 	if (i == 0 || i == nb_line - 1)
	// 	{
	// 		printf("line[%i] -> %s", i, map[i]);
	// 		if (!check_first_and_last_line(map[i]))
	// 		{
	// 			printf("ici1\n");
	// 			return (0);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (!check_intermediate_line(map[i]))
	// 		{
	// 			printf("ici2\n");
	// 			return (0);
	// 		}
	// 	}
	// }
	// if (!check_char_map(map))
	// 	return (0);
	// // if (!check_if_map_closed(map))
	// 	// return (0);
	return (1);
}

int	check_map(char **map, t_all *all)
{
	int	i;

	i = 0;
	if (!parsing_data_map(map, &i, all->map))
	{
		printf("Error: data parsing\n");
		return (0);
	}
	while (map[i] && map[i][0] == '\n')
		i++;
	if (!parsing_body_map(&map[i], all))
	{
		printf("Error: map invalid\n");
		return (0);
	}
	return (1);
}
