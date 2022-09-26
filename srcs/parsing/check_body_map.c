/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:07:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/27 00:09:23 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_first_and_last_line(t_all *all, int last_line)
{
	int	i;
	int	j;

	i = -1;
	while (all->map->map[++i])
	{
		j = 0;
		if (i == 0 || i == last_line)
		{
			while (all->map->map[i][j] && all->map->map[i][j] != '\n')
			{
				if (all->map->map[i][j] != '1'
					&& all->map->map[i][j] != ' ')
					return (0);
				j++;
			}
		}
	}
	return (1);
}

static int	check_intermediate_line(t_all *all, int last_line)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (all->map->map[++i] && i < last_line)
	{
		size_map(all, all->map->map[i]);
		start = all->map->start_line;
		end = all->map->end_line;
		if (all->map->map[i][start] != '1' || all->map->map[i][end] != '1')
			return (0);
		while (all->map->map[i][start++] && start < end)
		{
			if (all->map->map[i][start] == ' ')
				all->map->map[i][start] = '0';
			if (all->map->map[i][start] != '1'
			&& all->map->map[i][start] != '0'
			&& all->map->map[i][start] != 'N'
			&& all->map->map[i][start] != 'S'
			&& all->map->map[i][start] != 'E'
			&& all->map->map[i][start] != 'W')
				return (0);
		}
	}
	return (1);
}

static int	check_arround_space(char **arr, int i, int j)
{
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
		printf("%s", arr[i]);
		j = -1;
		while (arr[i][++j] && arr[i][j] != '\n')
		{
			if (arr[i][j] == '0')
				if (!check_arround_space(arr, i, j))
					return (0);
		}
	}
	return (1);
}

int	check_body_map(t_all *all)
{
	int	i;
	int	last_line;

	i = 0;
	while (all->map->map[i])
		i++;
	i -= 1;
	while (i != 0 && all->map->map[i][0] == '\n')
		i--;
	last_line = i;
	// pour avoir la bonne taille de la map c' est ici
	if (!check_first_and_last_line(all, last_line))
		return (0);
	if (!check_intermediate_line(all, last_line))
		return (0);
	if (!check_if_map_closed(all, last_line))
		return (0);
	return (1);
}
