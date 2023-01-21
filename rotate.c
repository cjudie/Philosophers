/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:37:02 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:04 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	null(void *nul)
{
	(void) nul;
}

void	ra(t_stack *stack)
{
	t_node	*next;
	int		*buff;

	if (!stack || !stack->a)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->a->first->content);
	next = stack->a->first->next;
	list_add_back(stack->a, buff);
	delete_list(stack->a, stack->a->first, free);
	stack->a->first = next;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	t_node	*next;
	int		*buff;

	if (!stack || !stack->b)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->b->first->content);
	next = stack->b->first->next;
	list_add_back(stack->b, buff);
	delete_list(stack->b, stack->b->first, null);
	stack->b->first = next;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_putstr_fd("rr\n", 1);
}
