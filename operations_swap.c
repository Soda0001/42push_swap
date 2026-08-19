/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:45:00 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/19 13:45:34 by odurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_node **head)
{
	t_node	*temp;

	if (!head || !*head || !(*head)->next)
		return ;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void op_sb(t_node **head)
{
	op_sa(head);
}