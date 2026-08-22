/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:09:11 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:15:03 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!*lst || !del)
		return ;
	current = *lst;
	temp = current;
	while (current)
	{
		temp = current->next;
		del((current)->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
