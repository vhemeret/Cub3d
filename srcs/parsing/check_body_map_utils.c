/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:04:16 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/25 18:39:18 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	width_map(t_all *all)
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
	all->map->width = width;
}

void	size_map(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	all->map->start_line = i;
	while (line[i] && line[i] != '\n')
		i++;
	if (line [i - 1])
	{
		i--;
		while (line[i] && line[i] == ' ' && i != 0)
			i--;
		all->map->end_line = i;
	}
}

void	replace_space(char **square)
{
	int	i;
	int	j;

	i = -1;
	while (square[++i])
	{
		j = -1;
		while (square[i][++j] && square[i][j] != '\n')
		{
			if (square[i][j] == ' ')
				square[i][j] = '*';
		}
	}
}

void	put_map_in_square(t_all *all, char **square, int last_line)
{
	int	i;
	int	j;

	i = -1;
	while (all->map->map[++i] && i <= last_line)
	{
		j = -1;
		size_map(all, all->map->map[i]);
		while (all->map->map[i][++j] && j <= all->map->end_line)
			square[i][j] = all->map->map[i][j];
		if (j < all->map->width)
		{
			j -= 1;
			while (++j < all->map->width - 1)
				square[i][j] = ' ';
			square[i][j] = '\n';
			square[i][j + 1] = '\0';
		}
		else
			square[i][j] = '\0';
	}
	square[last_line + 1] = NULL;
	replace_space(square);
}

char	**create_square(t_all *all, int last_line)
{
	int		i;
	int		j;
	size_t	size;
	char	**square;

	i = 0;
	while (all->map->map[i] && i <= last_line)
		i++;
	square = ft_malloc((sizeof(char *) * (i + 1)), &all->mem);
	if (!square)
		return (NULL);
	i = -1;
	j = 0;
	width_map(all);
	while (all->map->map[++i] && i <= last_line)
	{
		size = (sizeof(char) * (all->map->width + 1));
		square[j] = ft_malloc(size, &all->mem);
		if (!square[j])
			return (NULL);
		j++;
	}
	put_map_in_square(all, square, last_line);
	return (square);
}
