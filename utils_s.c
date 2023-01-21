/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:49:20 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:58:55 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	stack_init(void)
{
	t_stack	stack;

	stack.a = create_list();
	stack.b = create_list();
	return (stack);
}

void	stack_norm(t_lst	*stack)
{
	t_node	*current;
	t_index	copy;
	int		index;
	int		*value;

	copy = stack_indexing(stack);
	sort_by_index(&copy);
	current = stack->first;
	while (current != NULL)
	{
		index = find_index(&copy, *((int *) current->content));
		value = malloc(sizeof(int));
		*value = index;
		free(current->content);
		current->content = value;
		current = current->next;
	}
	free(copy.pointer);
}

t_node	*list_create_node(void *content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
