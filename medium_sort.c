/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/28 16:40:28 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 16:29:26 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static void	move_to_top_a(t_node **stack_a, int pos, int size, t_bench *bench)
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

static void	move_to_top_b(t_node **stack_b, int pos, int size, t_bench *bench)
{
	if (pos <= size - pos)
	{
		while (pos-- > 0)
			op_rb(stack_b, bench);
	}
	else
	{
		while (pos++ < size)
			op_rrb(stack_b, bench);
	}
}

static int	get_chunk_members_rank(t_node *stack_a, int start, int end)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->rank >= start && stack_a->rank < end)
			return (pos);
		pos++;
		stack_a = stack_a->next;
	}
	return (-1);
}

static void	push_chunks_to_b(t_node **stack_a, t_node **stack_b, int chunk_count, int chunk_size, t_bench *bench)
{
	int	i;
	int	pos;

	i = 0;
	while (i < chunk_count)
	{
		pos = get_chunk_members_rank(*stack_a, i * chunk_size, (i + 1) * chunk_size);
		while (pos != -1)
		{
			move_to_top_a(stack_a, pos, stack_size(*stack_a), bench);
			op_pb(stack_a, stack_b, bench);
			pos = get_chunk_members_rank(*stack_a, i * chunk_size, (i + 1) * chunk_size);
		}
		i++;
	}
}

static int	find_pos(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static int	find_max_rank(t_node *stack)
{
	int	max_rank;

	max_rank = stack->rank;
	while (stack)
	{
		if (stack->rank > max_rank)
			max_rank = stack->rank;
		stack = stack->next;
	}
	return (max_rank);
}

void	medium_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	n;
	int	chunk_size;
	int	chunk_count;
	int	max_rank;
	int	pos;

	if (try_sort_small(stack_a, bench))
		return ;
	rank_numbers(stack_a);
	n = stack_size(*stack_a);
	chunk_count = sqrt(n);
	chunk_size = (n + chunk_count - 1) / chunk_count;
	push_chunks_to_b(stack_a, stack_b, chunk_count, chunk_size, bench);
	while (*stack_b)
	{
		max_rank = find_max_rank(*stack_b);
		pos = find_pos(*stack_b, max_rank);
		move_to_top_b(stack_b, pos, stack_size(*stack_b), bench);
		op_pa(stack_a, stack_b, bench);
	}
}
