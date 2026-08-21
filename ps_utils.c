/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:26:26 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 06:40:04 by odurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	decide_algo(char *first_arg)
{
	if (ft_strcmp(first_arg, "--simple") == 0)
		return (STRAT_SIMPLE);
	else if (ft_strcmp(first_arg, "--medium") == 0)
		return (STRAT_MEDIUM);
	else if (ft_strcmp(first_arg, "--complex") == 0)
		return (STRAT_COMPLEX);
	else // ya-- adaptive olacak ya da boş olacak
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
