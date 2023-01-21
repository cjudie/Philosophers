/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:47:28 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 19:48:03 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_list(void)
{
	t_lst	*list;

	list = (t_lst *) malloc(sizeof(t_lst));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

void	clear_list(t_lst *list, void (*del)(void*))
{
	t_node	*current;
	t_node	*buff;

	if (list != NULL && del != NULL)
	{
		current = list->first;
		while (current != NULL)
		{
			buff = current->next;
			delete_list(list, current, del);
			current = buff;
		}
		free(list);
	}
}

void	delete_list(t_lst *list, t_node *node, void (*del)(void*))
{
	if (node != NULL)
	{
		del(node->content);
		free(node);
		list->size--;
	}
}

void	list_add_front(t_lst *list, void *content)
{
	t_node	*first;
	t_node	*last;
	t_node	*node;

	first = list->first;
	node = list_create_node(content);
	if (first == NULL)
		list->first = node;
	else
	{
		last = list->last;
		if (last == NULL)
			last = first;
		node->next = first;
		first->prev = node;
		list->first = node;
		list->last = last;
	}
	list->size++;
}

void	list_add_back(t_lst *list, void *content)
{
	t_node	*first;
	t_node	*node;

	node = list_create_node(content);
	first = list->first;
	if (first == NULL)
		list->first = node;
	else
	{
		if (list->last == NULL)
			list->last = first;
		list->last->next = node;
		list->last = node;
		node->prev = list->last;
	}
	list->size++;
}
