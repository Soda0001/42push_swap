/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:45:00 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/22 15:06:57 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_list **head)
{
	t_list	*temp;

	if (!head || !*head || !(*head)->next)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void	op_sb(t_list **head)
{
	op_sa(head);
}

void	op_ss(t_list **head_a, t_list **head_b)
{
	op_sa(head_a);
	op_sb(head_b);
}
