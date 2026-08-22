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

void	run_algo(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		printf("---simple---\n");
	if (strategy == STRAT_MEDIUM)
		printf("---medium---\n");
	if (strategy == STRAT_COMPLEX)
		printf("---complex---\n");
	else //(strategy == STRAT_ADAPTIVE)
		printf("---adaptive---\n");
}

