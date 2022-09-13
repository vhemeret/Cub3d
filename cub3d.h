/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/13 15:51:41 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*##################### LIBRARIES #####################*/

# include "minilibx_linux/mlx.h"
# include "srcs/get_next_line/get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

/*##################### STRUCTURES #####################*/

typedef struct s_init
{
	void	*mlx;
	void	*window;
}			t_init;
typedef struct s_data_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_data_img;

typedef struct s_map
{
	char	**map;
	int		line;
	int		column;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	double	vec_x;
	double	vec_y;
	int vue_x;
	int	vue_y;
}			t_player;

typedef struct s_face
{
	int	NO;
	int SO;
	int	WE;
	int	EA;
}	t_face;

typedef struct s_data_engine
{
	t_data_img		*img;
	t_data_img		*tmp;
	t_init			*init;
	t_map			*map;
	t_player		*player;
}				t_data_engine;

/*##################### PARSING #####################*/

int		manage_parsing(char *path, char **map);
int		check_fd(char *path);
char	**get_map(char *path);
int		check_map(char **map);

/*##################### DISPLAY #####################*/

void	display_map(t_data_engine	*engine);
void	put_pixel(t_data_engine *engine, void *img);
void	my_mlx_pixel_put(t_data_engine *data, int x, int y, int color);
unsigned int	get_color_pixel(t_data_engine *engine, void *img, int y, int x);
void	init(t_data_engine	**engine, char **map);

#endif