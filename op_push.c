/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_push.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	track_op(bench, OP_PA);
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*temp;

	if (!stack_a || !(*stack_a))
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	track_op(bench, OP_PB);
	ft_putstr_fd("pb\n", 1);
}
