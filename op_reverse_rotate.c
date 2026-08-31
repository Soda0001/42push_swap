/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_reverse_rotate.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_silent(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	prev = NULL;
	last = *head;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	op_rra(t_node **stack_a, t_bench *bench)
{
	reverse_rotate_silent(stack_a);
	track_op(bench, OP_RRA);
	ft_putstr_fd("rra\n", 1);
}

void	op_rrb(t_node **stack_b, t_bench *bench)
{
	reverse_rotate_silent(stack_b);
	track_op(bench, OP_RRB);
	ft_putstr_fd("rrb\n", 1);
}

void	op_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	reverse_rotate_silent(stack_a);
	reverse_rotate_silent(stack_b);
	track_op(bench, OP_RRR);
	ft_putstr_fd("rrr\n", 1);
}
