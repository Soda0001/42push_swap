/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder_utils.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/27 16:17:49 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/28 19:00:45 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mistakes(t_node *stack_a)
{
	t_node	*current;
	t_node	*temp;
	int		mistake;

	current = stack_a;
	temp = current;
	mistake = 0;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->content > temp->content)
				mistake++;
			temp = temp->next;
		}
		current = current->next;
	}
	return (mistake);
}

static int	count_pairs(int element_count)
{
	int	total_pairs;

	total_pairs = (element_count * (element_count - 1)) / 2;
	return (total_pairs);
}

double	compute_disorder(int element_count, t_node *stack_a)
{
	double	disorder;

	disorder = count_mistakes(stack_a) / count_pairs(element_count);
	return (disorder);
}
