/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:28:12 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/03 23:03:06 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 1920
#define height 1080

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

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "./textures/stone1.xpm", &img);
	load_image(info, info->texture[1], "./textures/stone2.xpm", &img);
	load_image(info, info->texture[2], "./textures/stone3.xpm", &img);
	load_image(info, info->texture[3], "./textures/stone4.xpm", &img);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.posX = 1.5;
	info.posY = 1.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;
	info.re_buf = 0;	
	info.texWidth = 64;
	info.texHeight = 64;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			info.buf[i][j] = 0;
		}
	}

	if (!(info.texture = (int **)malloc(sizeof(int *) * 4)))
		return (-1);
	for (int i = 0; i < 4; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (64 * 64))))
			return (-1);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 64 * 64; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.moveSpeed = 0.1001;
	info.rotSpeed = 0.05;
	
	info.win = mlx_new_window(info.mlx, width, height, "mlx");

	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 17, 0, mlx_loop_end, info.mlx);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop(info.mlx);
}
