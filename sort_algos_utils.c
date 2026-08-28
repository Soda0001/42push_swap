/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_algos_utils.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/27 14:23:04 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/28 19:15:11 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		op_sa(stack_a);
	else if (a > b && b > c)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		op_ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		op_rra(stack_a);
}
/*
** Kucuk yiginlar icin ozel cozumler.
** 1 eleman: zaten sirali, 2 eleman: en fazla 1 sa,
** 3 eleman: maksimum 2 hamlede sort_three ile cozulur.
*/

int	try_sort_small(t_node **stack_a)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			op_sa(stack_a);
		return (1);
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	return (0);
}
