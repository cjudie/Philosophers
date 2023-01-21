/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:10:54 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:07 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_lst
{
	struct s_node	*first;
	struct s_node	*last;
	unsigned int	size;
}	t_lst;

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
}	t_stack;

typedef struct s_index
{
	int		*pointer;
	int		size;
}	t_index;

int		int_checker(const char *nptr);
int		sort_checker(t_index *tab);
int		dup_checker(t_index *tab);
int		space_checker(int c);
int		put_error(char *str);

t_lst	*create_list(void);
void	clear_list(t_lst *list, void (*del)(void*));
void	delete_list(t_lst *list, t_node *node, void (*del)(void*));
void	list_add_front(t_lst *list, void *content);
void	list_add_back(t_lst *list, void *content);

t_stack	args_parser(int argc, char **argv);

t_stack	stack_init(void);
void	stack_norm(t_lst	*stack);
t_node	*list_create_node(void *content);

t_index	stack_indexing(t_lst *stack);
void	sort_by_index(t_index *index);
int		find_index(t_index *index, int value);

void	sort_small_stack(t_stack *stacks);
void	sort_big_stack(t_stack *stacks);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif
