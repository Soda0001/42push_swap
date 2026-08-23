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
	if (i < ac && !ft_strcmp(av[i], "--bench"))
	{
		*bench = 1;
		i++;
	}
	if (i < ac && !ft_strncmp(av[i], "--", 2))
	{
		*strategy = check_forced(av[i]);
		if (*strategy == STRAT_INVALID)
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

void	run_algo(t_strategy strategy, t_node **stack)
{
	if (strategy == STRAT_SIMPLE)
		simple_sort(stack);
	else if (strategy == STRAT_MEDIUM)
		medium_sort(stack);
	else if (strategy == STRAT_COMPLEX)
		complex_sort(stack);
	else
		adaptive_sort(stack);
}
