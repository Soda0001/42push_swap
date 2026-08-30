/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate2.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 13:45:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:27 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb(t_node **stack_b, t_bench *bench)
{
	reverse_rotate_silent(stack_b);
	track_op(bench, OP_RRB);
	ft_putstr_fd("rrb\n", 1);
}

void	op_rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rotate_silent(stack_a);
	rotate_silent(stack_b);
	track_op(bench, OP_RR);
	ft_putstr_fd("rr\n", 1);
}

void	op_rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	reverse_rotate_silent(stack_a);
	reverse_rotate_silent(stack_b);
	track_op(bench, OP_RRR);
	ft_putstr_fd("rrr\n", 1);
}
