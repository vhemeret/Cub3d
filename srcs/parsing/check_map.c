/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:57:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/04 23:42:55 by vahemere         ###   ########.fr       */
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
	if ((map[i][0] && map[i][0] == 'N') && (map[i][1] && map[i][1] == 'O'))
		face.NO = 1;
	else if ((map[i][0] && map[i][0] == 'S') && (map[i][1] && map[i][1] == 'O'))
		face.SO = 1;
	else if ((map[i][0] && map[i][0] == 'W') && (map[i][1] && map[i][1] == 'E'))
		face.WE = 1;
	else if ((map[i][0] && map[i][0] == 'E') && (map[i][1] && map[i][1] == 'A'))
		face.EA = 1;
	else
		return (0);
	if (face.NO == 0 || face.SO == 0 || face.WE == 0 || face.EA == 0)
		return (0);
	else
		printf("ok\n");
	return (1);
}

int	check_map(char **map)
{
	if (parsing_data_map(map))
		return (0);
	return (1);
}
