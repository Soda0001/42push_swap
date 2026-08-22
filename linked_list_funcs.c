/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:46:08 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/22 17:46:08 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_at_tail(t_node **lst, t_node *new)
{
	t_node	*last;

	last = *lst;
	if (last == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (last && last->next != NULL)
		last = last->next;
	last->next = new;
}