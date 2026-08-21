/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:25:41 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 06:29:56 by odurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_strategy	strategy;

	if (ac > 1)
		initialize_stack();
	strategy = decide_algo(av[1]);
	run_algo(strategy);
	return (0);
}
