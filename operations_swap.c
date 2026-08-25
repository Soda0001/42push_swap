/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:45:00 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/22 17:44:20 by sedeniz          ###   ########.fr       */
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

void	op_sa(t_node **head)
{
	swap_top(head);
	ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_node **head)
{
	swap_top(head);
	ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_node **head_a, t_node **head_b)
{
	swap_top(head_a);
	swap_top(head_b);
	ft_putstr_fd("ss\n", 1);
}
