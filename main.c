/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
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

static void	execute_sort(t_strategy strat, t_node **a,
				t_node **b, t_bench *bench)
{
	int		size;
	double	disorder;

	size = stack_size(*a);
	disorder = compute_disorder(size, *a);
	run_algo(strat, a, b, bench);
	if (bench->enabled)
		print_bench(strat, disorder, bench);
}

static int	init_stack_a(int ac, char **av,
				t_strategy *strat, t_node **stack_a)
{
	int	bench_enabled;

	if (parse_options(av, ac, strat, &bench_enabled) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	*stack_a = initialize_stack(av, ac);
	if (!*stack_a)
	{
		if (has_number_args(av, ac))
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		return (0);
	}
	return (bench_enabled);
}

int	main(int ac, char **av)
{
	t_strategy	strategy;
	t_node		*stack_a;
	t_node		*stack_b;
	t_bench		bench;
	int			bench_enabled;

	if (ac < 2)
		return (0);
	ft_memset(&bench, 0, sizeof(t_bench));
	stack_a = NULL;
	bench_enabled = init_stack_a(ac, av, &strategy, &stack_a);
	if (bench_enabled == -1)
		return (1);
	if (!stack_a)
		return (0);
	bench.enabled = bench_enabled;
	stack_b = NULL;
	execute_sort(strategy, &stack_a, &stack_b, &bench);
	free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}
