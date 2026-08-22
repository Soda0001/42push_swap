/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:46:46 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/22 17:44:16 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_node **head_a)
{
	t_node	*temp;
	t_node	*temp_head;

	if (!head_a || !*head_a || !(*head_a)->next)
		return ;
	temp_head = (*head_a)->next;
	temp = ft_lstlast(*head_a);
	(*head_a)->next = NULL;
	temp->next = *head_a;
	*head_a = temp_head;
}

void	op_rb(t_node **head_b)
{
	op_ra(head_b);
}

void	op_rra(t_node **head_a)
{
	t_node	*temp;

	if (!head_a || !*head_a || !(*head_a)->next)
		return ;
	temp = *head_a;
	*head_a = ft_lstlast(*head_a);
	(*head_a)->next = temp;
	while (temp)
	{
		if (temp->next == *head_a)
			break ;
		temp = temp->next;
	}
	temp->next = NULL;
}

void	op_rrb(t_node **head_b)
{
	op_rra(head_b);
}
