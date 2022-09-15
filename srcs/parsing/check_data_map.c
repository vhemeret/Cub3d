/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:12:53 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/14 17:40:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_value_rgb(char *line, t_map *data)
{
	char	**arr;
	char	**rgb;

	arr = ft_split(line, ' ');
	if (arr[1])
		rgb = ft_split(arr[1], ',');
	if (rgb)
	{
		if (!check_value(rgb))
		{
			free_double_arr(rgb);
			return (0);
		}
		put_rgb_data(arr, rgb, data);
		free_double_arr(rgb);
	}
	free_double_arr(arr);
	return (1);
}

int	check_rgb(char *map, t_face face, t_map *data)
{
	if (map[1])
	{
		if (map[1] != ' ' && map[1] != '\t')
			return (0);
		else
		{
			if (!wich_data(map, face))
				return (0);
			if (!check_value_rgb(map, data))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

int	check_texture(char *map, t_face face, t_map *data)
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
			arr = ft_split(map, ' ');
			if (arr[1])
			{
				if (!check_path_texture(arr[1]))
				{
					free_double_arr(arr);
					return (0);
				}
				put_path_data(arr, data);
			}	
			free_double_arr(arr);
		}
	}
	else
		return (0);
	return (1);
}

int	check_data(char **map, t_face face, t_map *data)
{	
	if (ft_strncmp(*map, "NO", 2) == 0 || ft_strncmp(*map, "SO", 2) == 0)
	{
		if (!check_texture(*map, face, data))
			return (0);
	}
	else if (ft_strncmp(*map, "WE", 2) == 0 || ft_strncmp(*map, "EA", 2) == 0)
	{
		if (!check_texture(*map, face, data))
			return (0);
	}
	else if (ft_strncmp(*map, "F", 1) == 0 || ft_strncmp(*map, "C", 1) == 0)
	{
		if (!check_rgb(*map, face, data))
			return (0);
	}
	else
		return (0);
	return (1);
}
