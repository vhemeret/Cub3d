/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:55:46 by brhajji-          #+#    #+#             */
/*   Updated: 2022/10/04 21:33:09 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"
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

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 1920
#define height 1080

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void	draw(t_info *info)
{
	//bzero(info->img.data, 1080*1920);
	mlx_destroy_image(info->mlx, info->img.img);
	info->img.img = mlx_new_image(info->mlx, width, height);
	//info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			info->img.data[y * width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int		get_num_tex(t_info *info, int mapX, int mapY)
{
	int texNum;

	texNum = 0;
	if (info->side == 0 && mapX - info->posX >= 0)
		texNum = 0;
	else if (info->side == 0 && mapX - info->posX < 0)
		texNum = 1;
	else if (info->side == 1 && mapY - info->posY < 0)
		texNum = 2;
	else if (info->side == 1 && mapY - info->posY >= 0)
		texNum = 3;
	return (texNum);
}

void	draw_color_texture(t_info *info, int x, int texNum, double step)
{
	double texPos;	
	int tmp = -1;
	int	y = info->drawStart -1;
	int	texY;
	int color;
	
	texPos = (info->drawStart - height / 2 + info->lineHeight / 2) * step;
	while (++tmp < info->drawStart)
		info->buf[tmp][x] = (65536 * 52 + 256 * 149 + 235); // a modifier all->map->c_rgb;
	tmp = info->drawEnd - 1;
	while (++tmp < 1080)
		info->buf[tmp][x] = 0XFFCC66; //  a modifier all->map->f_rgb;
	while (++y < info->drawEnd)
	{
		texY = (int)texPos & (info->texHeight - 1);
		texPos += step;
		color = info->texture[texNum][info->texHeight * texY + info->texX];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		info->re_buf = 1;
	}
}

void	init_calc(t_info *info, int *stepX, int *stepY, int *mapX, int *mapY)
{
	info->utils.deltaDistX = fabs(1 / info->utils.rayDirX);
	info->utils.deltaDistY = fabs(1 / info->utils.rayDirY);
	if (info->utils.rayDirX < 0)
	{
		*stepX = -1;
		info->utils.sideDistX = (info->posX - *mapX) * info->utils.deltaDistX;
	}
	else
	{
		*stepX = 1;
		info->utils.sideDistX = (*mapX + 1.0 - info->posX) * info->utils.deltaDistX;
	}
	if (info->utils.rayDirY < 0)
	{
		*stepY = -1;
		info->utils.sideDistY = (info->posY - *mapY) * info->utils.deltaDistY;
	}
	else
	{
		*stepY = 1;
		info->utils.sideDistY = (*mapY + 1.0 - info->posY) * info->utils.deltaDistY;
	}
}

void	draw_utils(t_info *info, int mapX, int mapY, int stepX, int stepY)
{
		if (info->side == 0)
			info->utils.perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / info->utils.rayDirX;
		else
			info->utils.perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / info->utils.rayDirY;
		info->lineHeight = (int)(height / info->utils.perpWallDist);
		info->drawStart = -info->lineHeight / 2 + height / 2;
		if(info->drawStart < 0)
			info->drawStart = 0;
		info->drawEnd = info->lineHeight / 2 + height / 2;
		if(info->drawEnd >= height)
			info->drawEnd = height - 1;
		if (info->side == 0)
			info->utils.wallX = info->posY + info->utils.perpWallDist * info->utils.rayDirY;
		else
			info->utils.wallX = info->posX + info->utils.perpWallDist * info->utils.rayDirX;
		info->utils.wallX -= floor(info->utils.wallX);
		info->texX = (int)(info->utils.wallX * (double)info->texWidth);
		if (info->side == 0 && info->utils.rayDirX > 0)
			info->texX = info->texWidth - info->texX - 1;
		if (info->side == 1 && info->utils.rayDirY < 0)
			info->texX = info->texWidth - info->texX - 1;
}

void	dda(t_info *info, int *mapX, int *mapY, int stepX, int stepY)
{
	while (1)
	{
		if (info->utils.sideDistX < info->utils.sideDistY)
		{
			info->utils.sideDistX += info->utils.deltaDistX;
			*mapX += stepX;
			info->side = 0;
		}
		else
		{
			info->utils.sideDistY += info->utils.deltaDistY;
			*mapY += stepY;
			info->side = 1;
		}
		if (worldMap[*mapX][*mapY] > 0)
			break;
	}
}

void	calc(t_info *info)
{
	int	x;
	int mapX;
	int mapY;
	int stepX;
	int stepY;

	x = -1;
	while (++x < width)
	{
		mapX = (int)info->posX;
		mapY = (int)info->posY;
		info->utils.rayDirX = info->dirX + info->planeX * ((double)(2 * x / (double)width - 1));
		info->utils.rayDirY = info->dirY + info->planeY * ((double)(2 * x / (double)width - 1));
		init_calc(info, &stepX, &stepY, &mapX, &mapY);
		dda(info, &mapX, &mapY, stepX, stepY);
		draw_utils(info, mapX, mapY, stepX, stepY);
		draw_color_texture(info, x, get_num_tex(info, mapX, mapY), (double)(1.0 * info->texHeight / info->lineHeight));
	}
}

int	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;
	
	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	if (!img->img)
		return (0);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	if (!img->data)
	{
		mlx_destroy_image(info->mlx, img->img);
		return (0);
	}
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}
