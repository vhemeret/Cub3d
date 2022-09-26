/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:12:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/26 23:41:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_virgule(char *rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		if (rgb[0] == ',')
			return (0);
		if (rgb[i] == ',')
		{	
			if (rgb[i + 1])
			{
				if (rgb[i + 1] == ',')
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

int	check_value_rgb(char *line, t_all *all)
{
	char	**arr;
	char	**rgb;

	rgb = NULL;
	arr = ft_split(line, ' ', all);
	if (arr[1])
	{
		if (!check_virgule(arr[1]))
			return (0);
		rgb = ft_split(arr[1], ',', all);
	}
	if (rgb)
	{
		if (!check_value(rgb))
			return (0);
		put_rgb_data(arr, rgb, all->map);
	}
	return (1);
}

int	check_rgb(char *map, t_face face, t_all *all)
{
	if (map[1])
	{
		if (map[1] != ' ' && map[1] != '\t')
			return (0);
		else
		{
			if (!wich_data(map, face))
				return (0);
			if (!check_value_rgb(map, all))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

int	check_texture(char *map, t_face face, t_all *all)
{
	char	**arr;

	if (map[2])
	{
		if (map[2] != ' ' && map[2] != '\t')
			return (0);
		else
		{
			if (!wich_data(map, face))
				return (0);
			arr = ft_split(map, ' ', all);
			if (arr[1])
			{
				if (!check_path_texture(arr[1], all))
					return (0);
				put_path_data(arr, all);
			}	
		}
	}
	else
		return (0);
	return (1);
}

int	check_data(char **map, t_face face, t_all *all)
{
	char	*line;
	
	if (*map[0] == ' ')
		line = remove_wspace(*map, all);
	else
		line = *map;
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0)
	{
		if (!check_texture(line, face, all))
			return (0);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		if (!check_texture(line, face, all))
			return (0);
	}
	else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		if (!check_rgb(line, face, all))
			return (0);
	}
	else
		return (0);
	return (1);
}
