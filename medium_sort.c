/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:40:28 by alterzi           #+#    #+#             */
/*   Updated: 2026/08/30 15:32:06 by sedeniz          ###   ########.tr       */
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

static void	move_to_top_a(t_node **stack_a, int pos, int size)
{
	if (pos <= size - pos)
	{
		while (pos-- > 0)
			op_ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			op_rra(stack_a);
	}
}

static void	move_to_top_b(t_node **stack_b, int pos, int size)
{
	if (pos <= size - pos)
	{
		while (pos-- > 0)
			op_rb(stack_b);
	}
	else
	{
		while (pos++ < size)
			op_rrb(stack_b);
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
		stack_a = stack_a->next;
	}
	return (-1);
}

static void	push_chunks_to_b(t_node **stack_a, t_node **stack_b, int chunk_number, int chunk_size)
{
	int	i;
	int	pos;

	i = 0;
	while (i < chunk_number)
	{
		pos = get_chunk_members_rank(*stack_a, i * chunk_size, (i + 1) * chunk_size);
		while (pos != -1)
		{
			move_to_top_a(stack_a, pos, stack_size(*stack_a));
			op_pb(stack_a, stack_b);
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

void	medium_sort(t_node **stack_a, t_node **stack_b)
{
	int	n;
	int	chunk_size;
	int	chunk_number;

	if (try_sort_small(stack_a))
		return ;
	//rank_numbers(stack_a); check this
	n = stack_size(*stack_a);
	chunk_number = sqrt(n);
	// chunk_size = n / chunk_number + 1; ör:30 ile 31 incele gereksiz chunk açıyor 30 da.
	chunk_size = (n + chunk_number - 1) / chunk_number;
	push_chunks_to_b(stack_a, stack_b, chunk_number, chunk_size);
	while (*stack_b)
	{
		int	max_rank;

		max_rank = find_max_rank(*stack_b);
		int	pos;

		pos = find_pos(*stack_b, max_rank);
		move_to_top_b(stack_b, pos, stack_size(*stack_b));
		op_pa(stack_a, stack_b);
	}
}
