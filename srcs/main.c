/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/24 04:37:44 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 1920
#define height 1080


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

/*int	main(int ac, char **av)
{
	t_all	*all;
	t_data_engine *engine;
	
	engine = NULL;
	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	if (ac == 2)
	{
		init(&engine);
		display_map(engine);
		//mlx_put_image_to_window(engine->init->mlx, engine->init->window,
		//	engine->img->img, 0, 0);
		//mlx_key_hook(engine->init->window, key_hook, engine);
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
}*/

int	main(void)
{
	t_info info;

	info.posX = 12;
	info.posY = 5;
	info.dirX = -1;
	info.dirY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	
	info.img = malloc(sizeof(t_data_img));
	info.mlx = mlx_init();
	info.t_width = 64;
	info.img->img = mlx_new_image(info.mlx, width, height);
	info.img->addr = mlx_get_data_addr(info.img->img, &info.img->bpp,
			&info.img->line_l, &info.img->endian);
	info.win = mlx_new_window(info.mlx, width, height, "mlx");
	info.no = malloc(sizeof(t_data_img));
	info.so = malloc(sizeof(t_data_img));
	info.we = malloc(sizeof(t_data_img));
	info.ea = malloc(sizeof(t_data_img));

	info.no->img = mlx_xpm_file_to_image(info.mlx, "./map/test_texture/1.xpm",
			&info.t_width, &info.t_width);
	info.no->addr = mlx_get_data_addr(info.no->img, &info.no->bpp,
			&info.no->line_l, &info.no->endian);
	info.so->img = mlx_xpm_file_to_image(info.mlx, "./map/test_texture/2.xpm",
			&info.t_width, &info.t_width);
	info.so->addr = mlx_get_data_addr(info.so->img, &info.so->bpp,
			&info.so->line_l, &info.so->endian);
	info.we->img = mlx_xpm_file_to_image(info.mlx, "./map/test_texture/3.xpm",
			&info.t_width, &info.t_width);
	info.we->addr = mlx_get_data_addr(info.we->img, &info.we->bpp,
			&info.we->line_l, &info.we->endian);
	info.ea->img = mlx_xpm_file_to_image(info.mlx, "./map/test_texture/4.xpm",
			&info.t_width, &info.t_width);
	info.ea->addr = mlx_get_data_addr(info.ea->img, &info.ea->bpp,
			&info.ea->line_l, &info.ea->endian);
	mlx_hook(info.win, 17, 0, mlx_loop_end, info.mlx);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
}
