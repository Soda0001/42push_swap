/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:46:46 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/22 18:02:14 by sedeniz          ###   ########.fr       */
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
	*head = first->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate_silent(t_node **head)
{
	t_node	*cur;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	cur = *head;
	while (cur->next->next)
		cur = cur->next;
	last = cur->next;
	cur->next = NULL;
	last->next = *head;
	*head = last;
}

void	op_ra(t_node **head_a)
{
	rotate_silent(head_a);
	ft_putstr_fd("ra\n", 1);
}

void	op_rb(t_node **head_b)
{
	rotate_silent(head_b);
	ft_putstr_fd("rb\n", 1);
}

void	op_rra(t_node **head_a)
{
	reverse_rotate_silent(head_a);
	ft_putstr_fd("rra\n", 1);
}
