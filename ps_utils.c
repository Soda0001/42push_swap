/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:26:26 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 13:04:48 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bench()
{
	
}

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
	int	i;

	i = 1;
	*strategy = STRAT_ADAPTIVE;
	*bench = 0;
	if (i < ac && !ft_strncmp(av[i], "--", 2))
	{
		strategy = check_forced(av[i]);
		if (!ft_strcmp(av[i], "--bench"))
			*bench = 1;
		else
			return (-1);
		i++;
	}
	if (i < ac && !ft_strcmp(av[i], "--bench"))
	{
		if (*bench)
			return (-1);
		*bench = 1;
		i++;
	}
	return (i);
}

int	determine_start(char *first_arg)
{
	int	starting_index;

	starting_index = 1;
	if (ft_strncmp(first_arg, "--", 2) == 0)
	{
		starting_index = 2;
		return (starting_index);
	}
	return (starting_index);
}


void	run_algo(t_strategy strategy, t_node **stack)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(stack);
	else if (strategy == STRAT_MEDIUM)
		medium_sort(stack);
	else if (strategy == STRAT_COMPLEX)
		complex_sort(stack);
	else if (strategy == STRAT_ADAPTIVE)
		adaptive_sort(stack);
}
