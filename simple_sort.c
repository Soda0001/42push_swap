/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **stack_a, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		op_sa(stack_a, bench);
	else if (a > b && b > c)
	{
		op_sa(stack_a, bench);
		op_rra(stack_a, bench);
	}
	else if (a > b && b < c && a > c)
		op_ra(stack_a, bench);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack_a, bench);
		op_ra(stack_a, bench);
	}
	else if (a < b && b > c && a > c)
		op_rra(stack_a, bench);
}

int	try_sort_small(t_node **stack_a, t_bench *bench)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			op_sa(stack_a, bench);
		return (1);
	}
	if (size == 3)
	{
		sort_three(stack_a, bench);
		return (1);
	}
	return (0);
}

static int	find_min_pos(t_node *stack)
{
	int	min;
	int	min_pos;
	int	pos;

	if (!stack)
		return (0);
	min = stack->content;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	move_to_top(t_node **stack_a, int pos, int size, t_bench *bench)
{
	if (pos <= size - pos)
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

	if (try_sort_small(stack_a, bench))
		return ;
	n = stack_size(*stack_a);
	i = 0;
	while (i < n)
	{
		pos = find_min_pos(*stack_a);
		move_to_top(stack_a, pos, stack_size(*stack_a), bench);
		op_pb(stack_a, stack_b, bench);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b, bench);
}
