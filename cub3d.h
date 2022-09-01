/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 04:30:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/08/30 22:46:26 by vahemere         ###   ########.fr       */
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

typedef struct s_mem
{
	struct s_mem	*next;
	void			*addr;
}				t_mem;

/*##################### PARSING #####################*/

int		manage_parsing(char *path, char **map);
int		check_fd(char *path);
char	**get_map(char *path);
int		check_map(char **map);

/*##################### EXEC #####################*/

#endif