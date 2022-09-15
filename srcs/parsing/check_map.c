/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/15 16:05:27 by vahemere         ###   ########.fr       */
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

int	check_top(char **map, t_pos *pos)
{
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	while (map[y][x] && map[y][x] != '1' && y != 0)
		y--;
	if (map[y][x] != '1')
		return (0);
	return (1);
}

int	check_bot(char **map, t_pos *pos)
{
	int	i;
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	i = 0;
	while (map[i])
		i++;
	while (map[y][x] && y < i && map[y][x] != '1')
		y++;
	if (map[y][x] != '1')
		return (0);
	return (1);
}

int	check_right(char **map, t_pos *pos)
{
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	while (map[y][x] && map[y][x] != '1' && map[y][x] != '\n')
	{
		if (!check_top(map, pos))
		{
		printf("ici1\n");
			return (0);
		}
		if (!check_bot(map, pos))
		{
		printf("ici22\n");
			return (0);
		}
		x++;
	}
	if (map[y][x])
	{
		if (map[y][x] == '\n')
		{
		printf("ici3\n");
			return (0);
		}
	}
	else
	{
		printf("ici4\n");
		return (0);
	}
	return (1);
}

int	check_left(char **map, t_pos *pos)
{
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	while (map[y][x] && map[y][x] != '1' && x != 0)
	{
		if (!check_top(map, pos))
			return (0);
		if (!check_bot(map, pos))
			return (0);
		x--;
	}
	if (map[y][x] != '1')
		return (0);
	return (1);
}

static int	parsing_body_map(char **map, t_all *all)
{
	// int	i;

	// i = -1;
	// while (map[++i])
	// 	printf("%s", map[i]);
	if (!get_position_player(map, all->pos))
		return (0);
	if (!check_right(map, all->pos))
		return (0);
	if (!check_left(map, all->pos))
	{
		printf("ici2\n");
		return (0);
	}
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
	all->pos = malloc(sizeof(t_pos));
	if (!all->pos)
		return (0);
	if (!parsing_body_map(&map[i], all))
	{
		printf("Error: map invalid\n");
		return (0);
	}
	return (1);
}
