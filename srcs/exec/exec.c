/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:31:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/04 20:15:35 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int malloc_texture(t_info *info)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			info->buf[i][j] = 0;
	}
	info->texture = malloc(sizeof(int *) * 4);
	if (!info->texture)
		return (0);
	i = -1;
	while (++i < 4)
	{
		info->texture[i] = malloc(sizeof(int *) * (64 * 64));
		if (!info->texture[i])
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (64 * 64))
			info->texture[i] = 0;
	}
	return (1);
}

int load_texture(t_info *info)
{
	t_img img;

	if (!malloc_texture(info))
		return (0);
	if (!load_image(info, info->texture[0], "./textures/stone1.xpm", &img))
		return (0);
	if (!load_image(info, info->texture[1], "./textures/stone1.xpm", &img))
		return (0);
	if (!load_image(info, info->texture[2], "./textures/stone1.xpm", &img))
		return (0);
	if (!load_image(info, info->texture[3], "./textures/stone1.xpm", &img))
		return (0);
	return (1);
}

int run_mlx(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
	{
		printf("Error: Failed to init Mlx\n");
		return (0);
	}
	info->win = mlx_new_window(info->mlx, width, height, "mlx");
	if (!info->win)
	{
		printf("Error: Failed to create window\n");
		return (0);
	}
	info->img.img = mlx_new_image(info->mlx, width, height);
	if (!info->img.img)
	{
		printf("Error: Failed to create image\n");
		return (0);
	}
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
											  &info->img.size_l, &info->img.endian);
	if (!load_texture(info))
		return (0);
	return (1);
}

int exec(t_all *all)
{
	t_info info;

	info.posX = 1.5;
	info.posY = 1.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;
	info.re_buf = 0;
	info.texWidth = 64;
	info.texHeight = 64;
	if (!run_mlx(&info))
		return (0);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 17, 0, mlx_loop_end, info.mlx);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop(info.mlx);
	return (1);
}