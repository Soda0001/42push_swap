/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:46:46 by odurmaz           #+#    #+#             */
/*   Updated: 2026/08/19 13:47:35 by odurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	op_ra()
{
	
}

void	op_rb()
{
	
}

void	op_rra(t_node **head_a)
{
	t_node	*temp;

	temp = *head_a;
	*head_a = ft_lstlast(head_a);
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
	op_rra(head_b)
}