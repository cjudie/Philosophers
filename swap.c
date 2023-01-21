/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:34:11 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:02 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_lst	*a;
	int		buff;

	if (!stack || !stack->a)
		return ;
	a = stack->a;
	buff = *((int *) a->first->next->content);
	*((int *) a->first->next->content) = *((int *) a->first->content);
	*((int *) a->first->content) = buff;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	t_lst	*b;
	int		buff;

	if (!stack || !stack->b)
		return ;
	b = stack->b;
	buff = *((int *) b->first->next->content);
	*((int *) b->first->next->content) = *((int *) b->first->content);
	*((int *) b->first->content) = buff;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack)
{
	t_node	*list;
	int		*buff;

	if (!stack->b)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->b->first->content);
	list_add_front(stack->a, buff);
	list = stack->b->first->next;
	delete_list(stack->a, stack->b->first, free);
	stack->b->first = list;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack)
{
	t_node	*list;
	int		*buff;

	if (!stack->a)
		return ;
	buff = malloc(sizeof(int));
	*buff = *((int *) stack->a->first->content);
	list_add_front(stack->b, buff);
	list = stack->a->first->next;
	delete_list(stack->a, stack->a->first, free);
	stack->a->first = list;
	ft_putstr_fd("pb\n", 1);
}
