/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:07:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/24 01:43:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	width_map(t_all *all)
{
	int	i;
	int	j;
	int	width;
	int	tab;

	i = -1;
	width = 0;
	while (all->map->map[++i])
	{
		j = 0;
		tab = 0;
		while (all->map->map[i][j])
			j++;
		if (j > width)
			width = j + tab;
	}
	return (width);
}

static void	start_end_line(int *start_line, int *end_line, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	*start_line = i;
	while (line[i] && line[i] != '\n')
		i++;
	if (line [i - 1])
	{
		i--;
		while (line[i] && line[i] == ' ' && i != 0)
			i--;
		*end_line = i;
	}
}


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
		start_end_line(&start, &end, all->map->map[i]);
		if (all->map->map[i][start] != '1' || all->map->map[i][end] != '1')
			return (0);
		while (all->map->map[i][start++] && start < end)
		{
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

static int	check_if_map_closed(t_all *all, int last_line)
{
	int		i;
	int		j;
	int		width;
	char	**square;
	int		start;
	int		end;
	
	i = 0;
	while (all->map->map[i] && i <= last_line)
		i++;
	square = ft_malloc((sizeof(char *) * (i + 1)), &all->mem);
	if (!square)
		return (0);
	i = -1;
	width = width_map(all);
	j = 0;
	while (all->map->map[++i] && i <= last_line)
	{
		square[j] = ft_malloc((sizeof(char) * (width + 1)), &all->mem);
		if (!square[j])
			return (0);
		j++;
	}
	i = -1;
	while (all->map->map[++i] && i <= last_line)
	{
		j = 0;
		start_end_line(&start, &end, all->map->map[i]);
		while (all->map->map[i][j] && j <= end)
		{
			square[i][j] = all->map->map[i][j];
			j++;
		}
		if (j < width)
		{
			while (j < width - 1)
			{
				square[i][j] = ' ';
				j++;
			}
			square[i][j] = '\n';
			square[i][j + 1] = '\0';
		}
		else
			square[i][j] = '\0';
	}
	square[last_line + 1] = NULL;
	i = -1;
	while (square[++i])
	{
		j = -1;
		while( square[i][++j] && square[i][j] != '\n')
		{
			if (square[i][j] == ' ')
				square[i][j] = '*';
		}
	}
	i = -1;
	while (square[++i])
	{
		j = -1;
		while (square[i][++j] && square[i][j] != '\n')
		{
			if (square[i][j] == '0')
			{
				if (square[i - 1][j])
					if (square[i - 1][j] == '*')
						return (0);
				if (square[i + 1][j])
					if (square[i + 1][j] == '*')
						return (0);
				if (square[i][j - 1])
					if (square[i][j - 1] == '*')
						return (0);
				if (square[i][j + 1])
					if (square[i][j + 1] == '*')
						return (0);
			}
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
	if (!check_first_and_last_line(all, last_line))
		return (0);
	if (!check_intermediate_line(all, last_line))
		return (0);
	if (!check_if_map_closed(all, last_line))
		return (0);
	return (1);
}