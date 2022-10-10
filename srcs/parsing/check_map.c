/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/10 17:36:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	parsing_data_map(char **map, int *i, t_all *all)
{
	t_face	face;

	face.no = 0;
	face.so = 0;
	face.we = 0;
	face.ea = 0;
	face.f = 0;
	face.c = 0;
	face.data = 0;
	*i = 0;
	while (map[*i] && face.data != 6)
	{
		if (map[*i][0] && map[*i][0] != '\n')
		{
			if (!check_data(&map[*i], face, all))
				return (0);
			face.data++;
		}
		(*i)++;
	}
	if (face.data != 6
		&& (face.no != 1 || face.so != 1 || face.we != 1 || face.ea != 1)
		&& (face.f != 1 || face.c != 1))
		return (0);
	return (1);
}

static int	parsing_body_map(char **map, t_all *all)
{
	int	i;

	i = 0;
	while (i <= all->map->last_line)
		i++;
	all->map->map = ft_malloc((sizeof(char *) * (i + 1)), &all->mem);
	if (!all->map->map)
		return (0);
	i = -1;
	while (map[++i] && i <= all->map->last_line)
		all->map->map[i] = map[i];
	all->map->map[i] = NULL;
	if (!check_body_map(all))
		return (0);
	return (1);
}

int	check_map(char **map, t_all *all)
{
	int	i;

	i = 0;
	if (!parsing_data_map(map, &i, all))
	{
		printf("Error: data parsing\n");
		return (0);
	}
	i += first_line(&map[i], all);
	last_line(&map[i], all);
	if (!parsing_body_map(&map[i], all))
	{
		printf("Error: map invalid\n");
		return (0);
	}
	return (1);
}
