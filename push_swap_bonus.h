/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:51:17 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:59:06 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "bonus/get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);

void	p(t_stack **a, t_stack **b);
void	r(t_stack **a);
void	rab(t_stack **a, t_stack **b);
void	rr(t_stack **a);
void	rrab(t_stack **a, t_stack **b);
void	s(t_stack **a);
void	ss(t_stack **a, t_stack **b);

int		check_args(int argc, char **argv);
void	free_mass(int size, char **mas);
void	warning(int code, char *mess);

void	checker(int argc, char **argv);
int		check_sort(t_stack *a, t_stack *b);

#endif