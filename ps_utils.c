/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ps_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/19 21:26:26 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 20:32:00 by alterzi         ###   ########.fr        */
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

static int	process_flag(char *arg, t_strategy *strat,
				int *strat_count, int *bench)
{
	t_strategy	curr;

	if (!ft_strcmp(arg, "--bench"))
	{
		if (*bench)
			return (-1);
		*bench = 1;
	}
	else if (!ft_strncmp(arg, "--", 2))
	{
		if (*strat_count > 0)
			return (-1);
		curr = check_forced(arg);
		if (curr == STRAT_INVALID)
			return (-1);
		*strat = curr;
		(*strat_count)++;
	}
	return (0);
}

int	parse_options(char **av, int ac, t_strategy *strategy, int *bench)
{
	int	i;
	int	strat_count;

	i = 1;
	*strategy = STRAT_ADAPTIVE;
	*bench = 0;
	strat_count = 0;
	while (i < ac)
	{
		if (process_flag(av[i], strategy, &strat_count, bench) == -1)
			return (-1);
		i++;
	}
	return (0);
}
