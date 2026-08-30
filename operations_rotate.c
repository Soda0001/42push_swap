/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:25 by alterzi         ###   ########.fr        */
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

void	op_rra(t_node **stack_a, t_bench *bench)
{
	reverse_rotate_silent(stack_a);
	track_op(bench, OP_RRA);
	ft_putstr_fd("rra\n", 1);
}
