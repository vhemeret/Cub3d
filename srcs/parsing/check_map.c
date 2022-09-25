/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/25 18:59:52 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int parsing_data_map(char **map, int *i, t_all *all)
{
	t_face face;
	int		j;

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
		j = 0;
		if (map[*i][j] == ' ')
			while (map[*i][j] && map[*i][j] == ' ')
				j++;
		if (map[*i][j] && map[*i][j] != '\n')
		{
			if (!check_data(&map[*i], face, all))
				return (0);
			face.data++;
		}
		(*i)++;
	}
	if (face.data != 6 && (face.NO != 1 || face.SO != 1 || face.WE != 1 || face.EA != 1) && (face.F != 1 || face.C != 1))
		return (0);
	return (1);
}

static int parsing_body_map(char **map, t_all *all)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	all->map->map = ft_malloc((sizeof(char *) * (i + 1)), &all->mem);
	if (!all->map->map)
		return (0);
	i = -1;
	while (map[++i])
		all->map->map[i] = map[i];
	all->map->map[i] = NULL;
	if (!check_body_map(all))
		return (0);
	return (1);
}

int check_map(char **map, t_all *all)
{
	int i;

	i = 0;
	if (!parsing_data_map(map, &i, all))
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
