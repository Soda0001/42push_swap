/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_rotate.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_silent(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = find_last_node(*head);
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

void	op_ra(t_node **stack_a, t_bench *bench)
{
	rotate_silent(stack_a);
	track_op(bench, OP_RA);
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_node **stack_b, t_bench *bench)
{
	rotate_silent(stack_b);
	track_op(bench, OP_RB);
	ft_putstr_fd("rb\n", 1);
}

void	op_rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rotate_silent(stack_a);
	rotate_silent(stack_b);
	track_op(bench, OP_RR);
	ft_putstr_fd("rr\n", 1);
}
