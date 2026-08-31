/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   adaptive_sort.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int		size;
	double	disorder;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	disorder = compute_disorder(size, *stack_a);
	if (disorder < 0.2)
		simple_sort(stack_a, stack_b, bench);
	else if (disorder < 0.5)
		medium_sort(stack_a, stack_b, bench);
	else
		complex_sort(stack_a, stack_b, bench);
}

void	run_algo(t_strategy strategy, t_node **a, t_node **b, t_bench *bench)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(a, b, bench);
	else if (strategy == STRAT_MEDIUM)
		medium_sort(a, b, bench);
	else if (strategy == STRAT_COMPLEX)
		complex_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}
