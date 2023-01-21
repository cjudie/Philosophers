/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:18:31 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:58:59 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_parser(int position, t_stack *stacks, int argc, char **argv)
{
	size_t	i;
	int		*buff;

	i = position;
	while (i < (size_t) argc)
	{
		if (!int_checker(argv[i]))
		{
			put_error("Error!\n");
			exit(1);
		}
		buff = malloc(sizeof(int));
		*buff = ft_atoi(argv[i]);
		list_add_back(stacks->a, buff);
		i++;
	}
}

static void	words_parser(t_stack *stacks, char *str)
{
	char	**words;
	size_t	i;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i] != NULL)
		i++;
	arr_parser(0, stacks, i, words);
	i = 0;
	while (words[i] != NULL)
		free(words[i++]);
	free(words);
}

t_stack	args_parser(int argc, char **argv)
{
	t_stack	stacks;

	stacks = stack_init();
	if (argc == 2 && !int_checker(argv[1]))
		words_parser(&stacks, argv[1]);
	else
		arr_parser(1, &stacks, argc, argv);
	return (stacks);
}
