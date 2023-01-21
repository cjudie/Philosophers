/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:21 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:05 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	t_index	index;

	stacks = args_parser(argc, argv);
	index = stack_indexing(stacks.a);
	if (dup_checker(&index))
	{
		if (!sort_checker(&index))
		{
			stack_norm(stacks.a);
			if (stacks.a->size > 5)
				sort_big_stack(&stacks);
			else
				sort_small_stack(&stacks);
		}
	}
	else
		put_error("Error!\n");
	free(index.pointer);
	clear_list(stacks.a, free);
	clear_list(stacks.b, free);
	return (0);
}
