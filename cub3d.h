/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/13 21:21:57 by vahemere         ###   ########.fr       */
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

// typedef struct s_mem
// {
// 	struct s_mem	*next;
// 	void			*addr;
// }				t_mem;

typedef struct s_face
{
	int	NO;
	int SO;
	int	WE;
	int	EA;
}	t_face;

/*##################### PARSING #####################*/

int		manage_parsing(char *path, char **map);
int		check_fd(char *path);
char	**get_map(char *path);
int		check_map(char **map);
int		check_face_texture(char **m, t_face face);
int		check_path_texture(char **map);
int		check_data_rgb(char **map);
int		check_value_rgb(char **map);
int		check_value(char **rgb);

/*##################### EXEC #####################*/

/*##################### CLEANING #####################*/

void	free_double_arr(char **arr);

/*##################### UTILS #####################*/

char	**ft_split(char const *s, char c);
char	*remove_wspace(char *str);
int		ft_atoi(const char *nptr);

#endif