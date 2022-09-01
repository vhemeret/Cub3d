/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/08/30 22:41:12 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	char	**map;
	t_garb	*garb;

	map = NULL;
	garb = malloc(sizeof(t_mem));
	if (!garb)
		return (0);
	if (ac == 2)
	{
		if (!manage_parsing(av[1], map, garb))
		{
			// free_all(mem);
			return (0);
		}
		// else
		// 	manage_process(av,map);
	}
	else
		printf("Error\nThe number of argument are invalid.\n");
	return (0);
}
