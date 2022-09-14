/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:12:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/13 21:34:42 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_path_texture(char **map)
{
	int			i;
	int			fd;
	char		**arr;
	char		*path;

	i = -1;
	while (++i < 4)
	{
		arr = ft_split(map[0], ' ');
		if (arr)
		{
			path = remove_wspace(arr[1]);
			free_double_arr(arr);
			fd = open(path, O_RDONLY);
			free(path);
			path = NULL;
			if (fd == -1)
				return (0);
			close(fd);
		}
		else
			return (0);
	}
	return (1);
}

int	check_face_texture(char **m, t_face face)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if ((m[i][0] && m[i][0] == 'N') && (m[i][1] && m[i][1] == 'O')
			&& m[i][2] && m[i][2] == ' ')
			face.NO = 1;
		else if ((m[i][0] && m[i][0] == 'S') && (m[i][1] && m[i][1] == 'O')
			&& m[i][2] && m[i][2] == ' ')
			face.SO = 1;
		else if ((m[i][0] && m[i][0] == 'W') && (m[i][1] && m[i][1] == 'E')
			&& m[i][2] && m[i][2] == ' ')
			face.WE = 1;
		else if ((m[i][0] && m[i][0] == 'E') && (m[i][1] && m[i][1] == 'A')
			&& m[i][2] && m[i][2] == ' ')
			face.EA = 1;
		else
			return (0);
	}
	if (face.NO != 1 || face.SO != 1 || face.WE != 1 || face.EA != 1)
		return (0);
	if (!check_path_texture(m))
		return (0);
	return (1);
}

int	check_value(char **rgb)
{
	int	r;
	int	g;
	int	b;
	int	i;
	int	nb;

	r = 0;
	g = 0;
	b = 0;
	i = -1;
	while (++i < 3)
	{
		nb = ft_atoi(rgb[i]);
		if (nb < 0 || nb > 255)
			return (0);
		if (i == 0)
			r = 1;
		else if (i == 1)
			g = 1;
		else
			b = 1;
	}
	if (r != 1 || g != 1 || b != 1)
		return (0);
	return (1);
}

int	check_value_rgb(char **map)
{
	int		i;
	char	**arr;
	char	**rgb;

	i = -1;
	while (++i < 2)
	{
		arr = ft_split(map[i], ' ');
		if (arr[1])
			rgb = ft_split(arr[1], ',');
		free_double_arr(arr);
		if (rgb)
		{
			if (!check_value(rgb))
			{
				free_double_arr(rgb);
				return (0);
			}
			free_double_arr(rgb);
		}
	}
	return (1);
}

int	check_data_rgb(char **map)
{
	int	i;
	int	f;
	int	c;

	i = -1;
	f = 0;
	c = 0;
	while (++i < 2)
	{
		if (map[i][0] && (map[i][0] == 'F' || map[i][0] == 'C')
			&& map[i][1] && map[i][1] == ' ')
		{
			if (map[i][0] == 'F')
				f = 1;
			else if (map[i][0] == 'C')
				c = 1;
		}
		else
			return (0);
	}
	if (f != 1 || c != 1)
		return (0);
	if (!check_value_rgb(map))
		return (0);
	return (1);
}
