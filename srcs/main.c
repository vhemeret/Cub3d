/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/14 16:53:43 by brhajji-         ###   ########.fr       */
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
	char	**map;
	t_data_engine	*engine;

	engine = NULL;
	map = NULL;
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
		if (!manage_parsing(av[1], map))
			return (0);
<<<<<<< HEAD
		}
=======
		// else
		// 	manage_process(av,map);
>>>>>>> 47437ea73b501c5c9cc357e73f57524be2377808
	}
	else
		printf("Error\nThe number of argument are invalid.\n");
	return (0);
}
