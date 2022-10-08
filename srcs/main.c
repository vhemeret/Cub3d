/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/08 02:57:04 by brhajji-         ###   ########.fr       */
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
		else
			exec(all);
	}
	else
		printf("Error\nThe number of argument are invalid.\n");
	free_all(&all->mem);
	free(all);
	return (0);
}
