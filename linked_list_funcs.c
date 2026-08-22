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

void	insert_at_tail(t_node **lst, t_node *new)
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

void	insert_at_head(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_node	*new_node(int content)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

t_node	*find_last_node(t_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}