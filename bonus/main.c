/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:37:19 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:41 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	**check_one_string(int *argc, char **argv, int *flag)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!ft_strrchr(argv[1], ' '))
	{
		*argc = 1;
		return (argv);
	}
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		return (0);
	while (tmp[i])
		i++;
	*argc = i;
	*flag = 1;
	return (tmp);
}

int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc == 2)
		argv = check_one_string(&argc, argv, &flag);
	if (argc == 1 && !flag)
		exit(0);
	if (!flag)
	{
		argv++;
		argc--;
	}
	if (!check_args(argc, argv))
		warning(1, "Error!\n");
	checker(argc, argv);
	if (flag)
		free_mass(argc, argv);
	return (0);
}
