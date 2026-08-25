/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:20:21 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/19 18:20:27 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb(t_node **head_b)
{
	reverse_rotate_silent(head_b);
	ft_putstr_fd("rrb\n", 1);
}

void	op_rr(t_node **head_a, t_node **head_b)
{
	rotate_silent(head_a);
	rotate_silent(head_b);
	ft_putstr_fd("rr\n", 1);
}

void	op_rrr(t_node **head_a, t_node **head_b)
{
	reverse_rotate_silent(head_a);
	reverse_rotate_silent(head_b);
	ft_putstr_fd("rrr\n", 1);
}
