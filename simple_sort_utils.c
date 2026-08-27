/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:23:04 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/27 14:23:07 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	find_position(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	move_to_top(t_node **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			op_ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			op_rra(a);
			pos++;
		}
	}
}

void	selection_sort(t_node **a, t_node **b)
{
	int	min;
	int	pos;
	int	size;

	size = stack_size(*a);
	while (size > 0)
	{
		min = find_min(*a);
		pos = find_position(*a, min);
		move_to_top(a, pos, size);
		op_pb(a, b);
		size--;
	}
	while (*b)
		op_pa(a, b);
}
