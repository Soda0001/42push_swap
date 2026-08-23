/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:25:41 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 13:04:22 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_strategy	strategy;
	t_node		*stack;
	int			bench;
	int			start;

	if (ac < 2)
		return (0);
	start = parse_options(av, ac, &strategy, &bench);
	if (start == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack = initialize_stack(av, ac, start);
	run_algo(strategy, &stack);
	free_stack(&stack);
	return (0);
}
