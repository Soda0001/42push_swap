/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_swap.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:29 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	op_sa(t_node **stack_a, t_bench *bench)
{
	swap_top(stack_a);
	track_op(bench, OP_SA);
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_node **stack_b, t_bench *bench)
{
	swap_top(stack_b);
	track_op(bench, OP_SB);
	ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	swap_top(stack_a);
	swap_top(stack_b);
	track_op(bench, OP_SS);
	ft_putstr_fd("ss\n", 1);
}
