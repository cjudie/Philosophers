/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:13:35 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:05 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*node;
	int		*buff;

	if (!stack || !stack->a)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->a->last->content);
	node = stack->a->last->prev;
	node->next = NULL;
	stack->a->last = node;
	list_add_front(stack->a, buff);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	int		*buff;

	if (!stack || !stack->b)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->b->last->content);
	prev = stack->b->last->prev;
	prev->next = NULL;
	list_add_front(stack->b, buff);
	delete_list(stack->b, stack->b->last, free);
	stack->b->last = prev;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_putstr_fd("rrr\n", 1);
}
