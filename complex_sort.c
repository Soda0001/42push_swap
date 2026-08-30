/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex_sort.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/29 03:00:45 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	get_max_rank(t_node *stack)
{
	int	max_rank;

	max_rank = 0;
	while (stack)
	{
		if (stack->rank > max_rank)
			max_rank = stack->rank;
		stack = stack->next;
	}
	return (max_rank);
}

static void process_bit(t_node * *stack_a, t_node * *stack_b,
	int	bit, int size, t_bench *bench)
{
	int	i;

	i = 0;
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
	int	size;
	int	max_rank;
	int	bit;

	rank_numbers(stack_a);
	size = get_stack_size(*stack_a);
	max_rank = get_max_rank(*stack_a);
	bit = 0;
	while ((max_rank >> bit) != 0)
	{
		process_bit(stack_a, stack_b, bit, size, bench);
		bit++;
	}
}
