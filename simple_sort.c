/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/28 19:12:13 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:37 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

static int	find_pos(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack->content != value)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	move_to_top(t_node **stack_a, int pos, int size, t_bench *bench)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_ra(stack_a, bench);
	}
	else
	{
		while (pos++ < size)
			op_rra(stack_a, bench);
	}
}

void	simple_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	n;
	int	i;
	int	pos;
	int	size;
	int	min;

	if (try_sort_small(stack_a, bench))
		return ;
	n = stack_size(*stack_a);
	i = 0;
	while (i < n)
	{
		min = find_min(*stack_a);
		size = stack_size(*stack_a);
		pos = find_pos(*stack_a, min);
		move_to_top(stack_a, pos, size, bench);
		op_pb(stack_a, stack_b, bench);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b, bench);
}
