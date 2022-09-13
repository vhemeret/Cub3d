/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/13 21:35:43 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	parsing_data_map(char **map)
{
	int		i;
	t_face	face;

	face.NO = 0;
	face.SO = 0;
	face.WE = 0;
	face.EA = 0;
	i = 0;
	while (map[i] && map[i][0] == '\n')
		i++;
	if (!check_face_texture(&map[i], face))
		return (0);
	i = 0;
	while (i < 5)
		i++;
	while (map[i] && map[i][0] == '\n')
		i++;
	if (!check_data_rgb(&map[i]))
		return (0);
	return (1);
}

int	check_map(char **map)
{
	if (!parsing_data_map(map))
	{
		printf("Error: data parsing\n");
		return (0);
	}
	// if (!parsing_body_map(map))
	// {
	// 	printf("Error: map invalid\n");
	// 	return (0);
	// }
	return (1);
}
