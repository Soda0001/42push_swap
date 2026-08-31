/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium_sort.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/28 16:40:28 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:32:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_chunks_to_b(t_node **stack_a, t_node **stack_b,
				int chunk_count, t_bench *bench)
{
	int	i;
	int	pos;
	int	chunk_size;
	int	total;

	total = stack_size(*stack_a);
	chunk_size = (total + chunk_count - 1) / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		pos = get_chunk_members_rank(*stack_a, i * chunk_size,
				(i + 1) * chunk_size);
		while (pos != -1)
		{
			move_to_top_a(stack_a, pos, stack_size(*stack_a), bench);
			op_pb(stack_a, stack_b, bench);
			pos = get_chunk_members_rank(*stack_a, i * chunk_size,
					(i + 1) * chunk_size);
		}
		i++;
	}
}

void	medium_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	n;
	int	chunk_count;
	int	max_rank;
	int	pos;

	if (try_sort_small(stack_a, bench))
		return ;
	rank_numbers(stack_a);
	n = stack_size(*stack_a);
	chunk_count = ft_sqrt(n);
	push_chunks_to_b(stack_a, stack_b, chunk_count, bench);
	while (*stack_b)
	{
		max_rank = find_max_rank(*stack_b);
		pos = find_pos_by_rank(*stack_b, max_rank);
		move_to_top_b(stack_b, pos, stack_size(*stack_b), bench);
		op_pa(stack_a, stack_b, bench);
	}
}
