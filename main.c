/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 21:25:41 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:16 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_number_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[i], "--", 2) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_strategy	strategy;
	t_node		*stack_a;
	t_node		*stack_b;
	t_bench		bench;
	int			bench_enabled;
	int			size;
	double		disorder;

	if (ac < 2)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	if (parse_options(av, ac, &strategy, &bench_enabled) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	bench.enabled = bench_enabled;
	stack_a = initialize_stack(av, ac);
	if (!stack_a)
	{
		if (has_number_args(av, ac))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		return (0);
	}
	stack_b = NULL;
	size = stack_size(stack_a);
	disorder = compute_disorder(size, stack_a);
	run_algo(strategy, &stack_a, &stack_b, &bench);
	if (bench_enabled)
		print_bench(strategy, disorder, &bench);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
