/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/19 11:09:23 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_hook(int keycode, t_data_engine	*engine)
{
	if (keycode == 65307)
	{
		mlx_loop_end(engine->init->mlx);
		return (0);
	}
	else if (keycode == 65364 && engine->player->vue_y + 100 <= 1080)
		engine->player->vue_y += 100;
	else if (keycode == 65362 && engine->player->vue_y - 100 <= 0)
		engine->player->vue_y -= 100;
	put_pixel(engine, NULL);
	mlx_put_image_to_window(engine->init->mlx, engine->init->window,
		engine->img->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	*all;

	engine = NULL;
	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (ac == 2)
	{
		init(&engine);
		display_map(engine);
		mlx_put_image_to_window(engine->init->mlx, engine->init->window,
			engine->img->img, 0, 0);
		mlx_key_hook(engine->init->window, key_hook, engine);
		mlx_loop_hook(engine->init->mlx, &main_loop, engine);
		mlx_hook(engine->init->window, 17, 0, mlx_loop_end, engine->init->mlx);
		mlx_loop(engine->init->mlx);
		if (!manage_parsing(av[1], all))
			return (0);
		// else
		// 	manage_process(av,map);
	}
	else
		printf("Error\nThe number of argument are invalid.\n");
	return (0);
}
