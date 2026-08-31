/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ps_utils.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 21:26:26 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 17:36:59 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	check_forced(char *forced_command)
{
	if (ft_strncmp(forced_command, "--", 2) != 0)
		return (STRAT_ADAPTIVE);
	if (ft_strcmp(forced_command, "--simple") == 0)
		return (STRAT_SIMPLE);
	if (ft_strcmp(forced_command, "--medium") == 0)
		return (STRAT_MEDIUM);
	if (ft_strcmp(forced_command, "--complex") == 0)
		return (STRAT_COMPLEX);
	if (ft_strcmp(forced_command, "--adaptive") == 0)
		return (STRAT_ADAPTIVE);
	return (STRAT_INVALID);
}

int	parse_options(char **av, int ac, t_strategy *strategy, int *bench)
{
	int			i;
	int			strat_count;
	t_strategy	current_strategy;

	i = 1;
	*strategy = STRAT_ADAPTIVE;
	*bench = 0;
	strat_count = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "--bench"))
		{
			if (*bench)
				return (-1);
			*bench = 1;
		}
		else if (!ft_strncmp(av[i], "--", 2))
		{
			if (strat_count > 0)
				return (-1);
			current_strategy = check_forced(av[i]);
			if (current_strategy == STRAT_INVALID)
				return (-1);
			*strategy = current_strategy;
			strat_count++;
		}
		i++;
	}
	return (0);
}

void	run_algo(t_strategy strategy, t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(stack_a, stack_b, bench);
	else if (strategy == STRAT_MEDIUM)
		medium_sort(stack_a, stack_b, bench);
	else if (strategy == STRAT_COMPLEX)
		complex_sort(stack_a, stack_b, bench);
	else
		adaptive_sort(stack_a, stack_b, bench);
}

void	rank_numbers(t_node **initial_stack)
{
	t_node	*temp;
	t_node	*current;
	t_node	*head;
	int		counter;

	counter = 0;
	head = *initial_stack;
	current = head;
	while (current)
	{
		counter = 0;
		temp = head;
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
