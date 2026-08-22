/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:11:56 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 17:11:56 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_stack(char **av, int ac)
{
	t_node	*stack;
	int		starting_index;

	stack = NULL;
	starting_index = determine_start(av[1]);
	while (starting_index < ac)
	{
		insert_at_tail(&stack, new_node(ft_atoi(av[starting_index])));
		starting_index++;
	}
	return (stack);
}
