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
/* I dont even remember why i did this:

int	determine_start(char *first_arg)
{
	int	start_index;

	start_index = 1
	if (ft_strcmp(first_arg[0], '-'))
	{
		start_index = 2;
		return (start_index);
	}
	return (start_index);
}
*/

t_strategy	check_forced(char *first_arg)
{
	if (ft_strcmp(first_arg, "--simple") == 0)
		return (STRAT_SIMPLE);
	else if (ft_strcmp(first_arg, "--medium") == 0)
		return (STRAT_MEDIUM);
	else if (ft_strcmp(first_arg, "--complex") == 0)
		return (STRAT_COMPLEX);
	else
		return (STRAT_ADAPTIVE);
}

void	run_algo(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		/*simple*/
	else if (strategy == STRAT_MEDIUM)
		/*medium*/
	else if (strategy == STRAT_COMPLEX)
		/*complex*/
	else (strategy == STRAT_ADAPTIVE)
		/*adaptive*/
}
