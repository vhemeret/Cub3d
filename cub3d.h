/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/03 19:16:35 by brhajji-         ###   ########.fr       */
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
# include <stdlib.h>
# include <string.h>

/*##################### STRUCTURES #####################*/
typedef struct s_map
{
	char	*path_texture_no;
	char	*path_texture_so;
	char	*path_texture_we;
	char	*path_texture_ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	char	**map_full;
	char	**map;
	int		nb_line;
	int		line;
	int		column;
}	t_map;
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
typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;
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
	int	F;
	int C;
	int data;
}	t_face;

typedef struct s_data_engine
{
	t_data_img		*img;
	t_data_img		*tmp;
	t_init			*init;
	t_map			*map;
	t_player		*player;
}				t_data_engine;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_all
{
	t_map	*map;
	t_pos	*pos;
} t_all;

typedef	struct s_calc_utils
{
	double rayDirX;
	double rayDirY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double wallX;
	double perpWallDist;
}	t_calc_utils;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	int		buf[1080][1920];
	char	**map;
	int		**texture;
	int		texWidth;
	int		texHeight;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int 	side;
	int		texX;
	double	moveSpeed;
	double	rotSpeed;
	int		re_buf;
	int		t_width;
	t_img		img;
	t_calc_utils	utils;
}				t_info;


/*##################### PARSING #####################*/

int		manage_parsing(char *path, t_all *all);
int		check_fd(char *path);
char	**get_map(char *path);
int		check_map(char **map, t_all *all);
int		check_data(char **map, t_face face, t_map *data);
int		wich_data(char *data, t_face face);
int		check_path_texture(char *line);
int		check_value(char **rgb);
void	put_rgb_data(char **arr, char **rgb, t_map *data);
void	put_path_data(char **arr, t_map *data);
int		check_body_map(t_all *all);

int		get_position_player(char **map, t_pos *pos);

/*##################### DISPLAY #####################*/

int		get_position_player(char **map, t_pos *pos);
void	load_image(t_info *info, int *texture, char *path, t_img *img);



/*##################### CLEANING #####################*/

void	free_double_arr(char **arr);

/*##################### UTILS #####################*/

char	**ft_split(char const *s, char c);
char	*remove_wspace(char *str);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	display_map(t_data_engine	*engine);
void	put_pixel(t_data_engine *engine, void *img);
void	my_mlx_pixel_put(t_data_engine *data, int x, int y, int color);
unsigned int	get_color_pixel(void *img, t_data_img *el, int y, int x);
void	init(t_data_engine	**engine);
int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
void	key_press_suite(int key, t_info *info);
void	key_press_end(int key, t_info *info);
#endif