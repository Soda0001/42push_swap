/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 21:25:41 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/26 00:14:20 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_strategy	strategy;
	t_node		*stack_a;
	t_node		*stack_b;
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
	stack_a = initialize_stack(av, ac, start);
	if (start < ac && !stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_b = NULL;
	run_algo(strategy, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
