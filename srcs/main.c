/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/24 01:42:46 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->mem = NULL;
	if (ac == 2)
	{
		if (!manage_parsing(av[1], all))
		{	
			free_all(&all->mem);
			free(all);
			return (0);
		}
		// else
		// 	manage_process(av,map);
	}
	else
		printf("Error\nThe number of argument are invalid.\n");
	free_all(&all->mem);		
	free(all);
	return (0);
}
