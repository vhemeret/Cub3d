/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:13:23 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/14 17:59:48 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_path_data(char **arr, t_map *data)
{
	if (arr[0][0] == 'N')
		data->path_texture_no = remove_wspace(arr[1]);
	else if (arr[0][0] == 'S')
		data->path_texture_so = remove_wspace(arr[1]);
	else if (arr[0][0] == 'W')
		data->path_texture_we = remove_wspace(arr[1]);
	else if (arr[0][0] == 'E')
		data->path_texture_ea = remove_wspace(arr[1]);
}

void	put_rgb_data(char **arr, char **rgb, t_map *data)
{
	if (arr[0][0] == 'F')
	{
		data->f_r = atoi(rgb[0]);
		data->f_g = atoi(rgb[1]);
		data->f_b = atoi(rgb[2]);		
	}
	else if (arr[0][0] == 'C')
	{
		data->c_r = atoi(rgb[0]);		
		data->c_g = atoi(rgb[1]);		
		data->c_b = atoi(rgb[2]);
	}
}

int	wich_data(char *data, t_face face)
{	
	if (data[0])
	{
		if (data[0] == 'N')
			face.NO = 1;
		else if (data[0] == 'S')
			face.SO = 1;
		else if (data[0] == 'W')
			face.WE = 1;
		else if (data[0] == 'E')
			face.EA = 1;
		else if (data[0] == 'F')
			face.F = 1;
		else if (data[0] == 'C')
			face.C = 1;
		else
			return (0);
	}
	else
	{
		(void)face;
		return (0);
	}
	return (1);
}

int	check_path_texture(char *line)
{
	int			fd;
	char		*path;

	path = remove_wspace(line);
	fd = open(path, O_RDONLY);
	free(path);
	path = NULL;
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_value(char **rgb)
{
	int	i;
	int	nb;

	i = -1;
	while (rgb[++i])
	{
		if (rgb[i][0])
			if (rgb[i][0] < '0' || rgb[i][0] > '9')
				return (0);
		nb = ft_atoi(rgb[i]);
		if (nb < 0 || nb > 255)
			return (0);
	}
	if (i > 3)
		return (0);
	return (1);
}
