/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:07:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/27 21:32:54 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_player_map(t_all *all)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (all->map->map[++i])
	{
		j = -1;
		while (all->map->map[i][++j] && all->map->map[i][j] != '\n')
		{
			if (all->map->map[i][j] == 'N'
				|| all->map->map[i][j] == 'S'
				|| all->map->map[i][j] == 'E'
				|| all->map->map[i][j] == 'W')
				player++;
		}
		if (player > 1)
			return (0);
	}
	if (player == 0)
		return (0);
	return (1);
}

static int	check_content_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map->map[++i])
	{
		j = -1;
		while (all->map->map[i][++j] && all->map->map[i][j] != '\n')
		{
			if (all->map->map[i][j] != '1'
			&& all->map->map[i][j] != '0'
			&& all->map->map[i][j] != 'N'
			&& all->map->map[i][j] != 'S'
			&& all->map->map[i][j] != 'E'
			&& all->map->map[i][j] != ' '
			&& all->map->map[i][j] != 'W')
				return (0);
		}
	}
	return (1);
}

static int	check_arround_space(t_all *all, char **arr, int i, int j)
{
	size_map(all, arr[i]);
	if (i == 0 || i == all->map->last_line || j == 0 || j == all->map->end_line)
		return (0);
	if (arr[i - 1][j])
		if (arr[i - 1][j] == '*')
			return (0);
	if (arr[i + 1][j])
		if (arr[i + 1][j] == '*')
			return (0);
	if (arr[i][j - 1])
		if (arr[i][j - 1] == '*')
			return (0);
	if (arr[i][j + 1])
		if (arr[i][j + 1] == '*')
			return (0);
	return (1);
}

static int	check_if_map_closed(t_all *all, int last_line)
{
	int		i;
	int		j;
	char	**arr;

	i = -1;
	arr = create_square(all, last_line);
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j] && arr[i][j] != '\n')
		{
			if (arr[i][j] == '0' || arr[i][j] == 'N'
				|| arr[i][j] == 'S' || arr[i][j] == 'E'
				|| arr[i][j] == 'W')
				if (!check_arround_space(all, arr, i, j))
					return (0);
		}
	}
	return (1);
}

int	check_body_map(t_all *all)
{
	if (!check_content_map(all))
		return (0);
	if (!check_player_map(all))
		return (0);
	if (!check_if_map_closed(all, all->map->last_line))
		return (0);
	return (1);
}
