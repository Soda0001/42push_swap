/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 03:00:45 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/29 03:00:46 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	get_max_rank(t_node *stack)
{
	int	max_rank;

	max_rank = 0;
	while (stack)
	{
		if (stack->rank > max_rank)
			max_rank = stack->rank;
		stack = stack->next;
	}
	return (max_rank);
}
