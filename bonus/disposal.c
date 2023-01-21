/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disposal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:37:03 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:38 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	p(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
}

void	r(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
}

void	rab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_stacklast(*a)->next = tmp;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_stacklast(*b)->next = tmp;
}

void	rr(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
}

void	rrab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*a);
	(*a) = tmp->next;
	tmp->next = NULL;
	tmp = (*b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*b);
	(*b) = tmp->next;
	tmp->next = NULL;
}
