/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:25:41 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/19 21:25:48 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_strategy	strategy;

	if (ac > 1)
		initialize_stack();
	strategy = decide_algo(av[1]);
	run_algo(strategy);
	return (0);
}
