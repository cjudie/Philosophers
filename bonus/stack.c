/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:37:21 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:43 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->value = value;
	res->next = NULL;
	return (res);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		(*lst) = new;
	else
		ft_stacklast(*lst)->next = new;
}
