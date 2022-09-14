/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:52:16 by vahemere          #+#    #+#             */
/*   Updated: 2022/09/13 21:24:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// static int	add_node(void *addr)
// {
// 	t_mem		*mem;
// 	t_mem		*tmp;

// 	mem = malloc(sizeof(t_mem));
// 	mem->addr = addr;
// 	mem->next = NULL;
// 	tmp = mem;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = mem;
// 	return (1);
// }

// void	*ft_malloc(size_t *size)
// {
// 	void	*addr;

// 	addr = malloc(size);
// 	add_node(addr);
// 	return (addr);
// }

// void	ft_free(void *addr)
// {
// 	t_mem	*mem;
// 	t_mem	*tmp;
// 	t_mem	*prev;

// 	tmp = mem;
// 	while (tmp)
// 	{
// 		mem = tmp->next;
// 		if (tmp->addr == addr)
// 		{
// 			free(tmp->addr);
// 			free(tmp);

// 		}
// 		prev = tmp;
// 		tmp = tmp->next;
// 	}
// }

// void	free_all()
// {
// 	t_mem *mem;
// 	t_mem *tmp;

// 	tmp = mem;
// 	while (tmp)
// 	{
// 		mem = tmp->next;
// 		free(tmp->addr);
// 		free(tmp);
// 		tmp = mem;
// 	}
// }