/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex_sort.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/29 03:00:45 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:32:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bit(t_node **stack_a, t_node **stack_b,
				int bit, t_bench *bench)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(*stack_a);
	while (i < size)
	{
		if ((((*stack_a)->rank >> bit) & 1) == 0)
			op_pb(stack_a, stack_b, bench);
		else
			op_ra(stack_a, bench);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b, bench);
}

void	complex_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	max_rank;
	int	bit;

	rank_numbers(stack_a);
	max_rank = find_max_rank(*stack_a);
	bit = 0;
	while ((max_rank >> bit) != 0)
	{
		process_bit(stack_a, stack_b, bit, bench);
		bit++;
	}
}
