/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:47:28 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:01 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index	stack_indexing(t_lst *stack)
{
	t_node	*current;
	t_index	index;
	size_t	i;

	i = 0;
	index.pointer = (int *) malloc(stack->size * sizeof(int));
	index.size = stack->size;
	current = stack->first;
	while (current != NULL)
	{
		index.pointer[i++] = *((int *) current->content);
		current = current->next;
	}
	return (index);
}

void	sort_by_index(t_index *index)
{
	int		current;
	int		buff;
	int		min;
	int		i;

	current = 0;
	while (current < index->size)
	{
		i = current;
		min = i;
		while (i < index->size)
		{
			if (index->pointer[i] < index->pointer[min])
				min = i;
			i++;
		}
		buff = index->pointer[current];
		index->pointer[current] = index->pointer[min];
		index->pointer[min] = buff;
		current++;
	}
}

int	find_index(t_index *index, int number)
{
	int	i;

	i = 0;
	while (i < index->size)
	{
		if (index->pointer[i] == number)
			return (i);
		else
			i++;
	}
	return (0);
}
