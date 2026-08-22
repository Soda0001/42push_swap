/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:45:00 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/22 14:56:05 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	op_pa(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	if (!head_b || !(*head_b))
		return ;
	temp = (*head_b)->next;
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = temp;
}

void	op_pb(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	if (!head_a || !(*head_a))
		return ;
	temp = (*head_a)->next;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = temp;
}
