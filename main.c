/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:25:41 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 13:04:22 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	t_strategy	strategy;
	t_list		*stack;

	strategy = check_forced(av[1]);
	stack = initialize_stack(av[1], ac);
	run_algo(strategy);
	return (0);
}
