/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:00:45 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/29 03:00:46 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	process_bit(t_node **stack_a, t_node **stack_b,
				int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*stack_a)->rank >> bit) & 1) == 0)
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b);
}

static void	process_bit(t_node **stack_a, t_node **stack_b,
				int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((((*stack_a)->rank >> bit) & 1) == 0)
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b);
}
