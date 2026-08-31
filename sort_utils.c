/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_utils.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:26:00 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rank_numbers(t_node **initial_stack)
{
	t_node	*temp;
	t_node	*current;
	int		counter;

	if (!initial_stack || !*initial_stack)
		return ;
	current = *initial_stack;
	while (current)
	{
		counter = 0;
		temp = *initial_stack;
		while (temp)
		{
			if (temp->content < current->content)
				counter++;
			temp = temp->next;
		}
		current->rank = counter;
		current = current->next;
	}
}

int	find_max_rank(t_node *stack)
{
	int	max_rank;

	if (!stack)
		return (-1);
	max_rank = stack->rank;
	while (stack)
	{
		if (stack->rank > max_rank)
			max_rank = stack->rank;
		stack = stack->next;
	}
	return (max_rank);
}

int	find_pos_by_rank(t_node *stack, int rank_val)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank == rank_val)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}
