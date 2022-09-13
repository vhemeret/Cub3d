/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:55:46 by brhajji-          #+#    #+#             */
/*   Updated: 2022/09/13 16:06:00 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

void	verLine(t_data_engine *engine, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(engine->init->mlx, engine->init->window, x, y, color);
		y++;
	}
}

void	calc(t_data_engine *engine)
{
	int	x;

	x = 0;
	while (x < 1080)
	{
		double cameraX = 2 * x / (double)1080 - 1;
		double rayDirX = engine->player->vec_x + 0 * cameraX;
		double rayDirY = engine->player->vec_y + 0.66 * cameraX;
		
		int mapX = (int)engine->player->x;
		int mapY = (int)engine->player->y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (engine->player->x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - engine->player->x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (engine->player->y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - engine->player->y) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (engine->map->map[mapX][mapY] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - engine->player->x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - engine->player->y + (1 - stepY) / 2) / rayDirY;

		//Calculate 1920 of line to draw on screen
		int line1920 = (int)(1920 / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -line1920 / 2 + 1920 / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = line1920 / 2 + 1920 / 2;
		if(drawEnd >= 1920)
			drawEnd = 1920 - 1;

		int	color;
		if (engine->map->map[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (engine->map->map[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (engine->map->map[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (engine->map->map[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		
		if (side == 1)
			color = color / 2;

		verLine(engine, x, drawStart, drawEnd, color);
		
		x++;
	}
}

int	main_loop(t_data_engine *engine)
{
	calc(engine);
	// mlx_put_image_to_window(engine->mlx, engine->win, &engine->img, 0, 0);

	return (0);
}

/*int	key_press(int key, t_data_engine *engine)
{
	if (key == K_W)
	{
		if (!engine->map->map[(int)(engine->player->x + engine->dirX * engine->moveSpeed)][(int)(engine->player->y)])
			engine->player->x += engine->dirX * engine->moveSpeed;
		if (!engine->map->map[(int)(engine->player->x)][(int)(engine->player->y + engine->player->vec_y * engine->moveSpeed)])
			engine->player->y += engine->player->vec_y * engine->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!engine->map->map[(int)(engine->player->x - engine->dirX * engine->moveSpeed)][(int)(engine->player->y)])
			engine->player->x -= engine->dirX * engine->moveSpeed;
		if (!engine->map->map[(int)(engine->player->x)][(int)(engine->player->y - engine->player->vec_y * engine->moveSpeed)])
			engine->player->y -= engine->player->vec_y * engine->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = engine->dirX;
		engine->dirX = engine->dirX * cos(engine->rotSpeed) - engine->player->vec_y * sin(engine->rotSpeed);
		engine->player->vec_y = oldDirX * sin(engine->rotSpeed) + engine->player->vec_y * cos(engine->rotSpeed);
		double oldPlaneX = engine->planeX;
		engine->planeX = engine->planeX * cos(engine->rotSpeed) - engine->planeY * sin(engine->rotSpeed);
		engine->planeY = oldPlaneX * sin(engine->rotSpeed) + engine->planeY * cos(engine->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = engine->dirX;
		engine->dirX = engine->dirX * cos(engine->rotSpeed) - engine->player->vec_y * sin(engine->rotSpeed);
		engine->player->vec_y = oldDirX * sin(engine->rotSpeed) + engine->player->vec_y * cos(engine->rotSpeed);
		double oldPlaneX = engine->planeX;
		engine->planeX = engine->planeX * cos(engine->rotSpeed) - engine->planeY * sin(engine->rotSpeed);
		engine->planeY = oldPlaneX * sin(engine->rotSpeed) + engine->planeY * cos(engine->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}*/