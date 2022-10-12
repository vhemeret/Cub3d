/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:52:16 by vahemere          #+#    #+#             */
/*   Updated: 2022/10/08 02:10:15 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	add_back_node(void *addr, t_mem *tmp)
{
	t_mem	*save;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_mem));
	if (!(tmp->next))
		return ;
	save = tmp;
	tmp = tmp->next;
	tmp->addr = addr;
	tmp->next = NULL;
	tmp->back = save;
}

static int	add_node(void *addr, t_mem **mem)
{
	t_mem	*tmp;

	if (!(*mem))
	{
		*mem = malloc(sizeof(t_mem));
		if (!mem)
			return (0);
		(*mem)->addr = addr;
		(*mem)->next = NULL;
		(*mem)->back = NULL;
		return (1);
	}
	else
		tmp = *mem;
	add_back_node(addr, tmp);
	return (1);
}

void	*ft_malloc(size_t size, t_mem **mem)
{
	void	*addr;

	addr = malloc(size);
	if (!add_node(addr, mem))
		return (NULL);
	return (addr);
}

void	ft_free(void *addr, t_mem **mem)
{
	t_mem	*tmp;
	t_mem	*prev;
	t_mem	*next;

	tmp = *mem;
	while (tmp)
	{
		prev = tmp->back;
		next = tmp->next;
		if (tmp->addr == addr)
		{
			free(tmp->addr);
			tmp->addr = NULL;
			free(tmp);
			tmp = NULL;
			prev->next = next;
			next->back = prev;
			return ;
		}
		tmp = tmp->next;
	}
}

void	free_all(t_mem **mem)
{
	t_mem	*tmp;

	tmp = *mem;
	if (tmp)
	{
		while (tmp)
		{
			*mem = tmp->next;
			free(tmp->addr);
			free(tmp);
			tmp = *mem;
		}
	}
}
