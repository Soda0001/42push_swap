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

void	op_rr(t_list **head_a, t_list **head_b)
{
	op_ra(head_a);
	op_rb(head_b);
}

void	op_rrr(t_list **head_a, t_list **head_b)
{
	op_rra(head_a);
	op_rrb(head_b);
}
