/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disposal2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:37:09 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:36 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	s(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if ((*b) && (*b)->next)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}

int	check_sort(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_mass(int size, char **mas)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mas[i]);
		i++;
	}
}

void	warning(int code, char *mess)
{
	if (code == 1)
		write(2, mess, ft_strlen(mess));
	if (code == 0)
		write(1, mess, ft_strlen(mess));
	exit(code);
}
