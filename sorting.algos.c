/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sorting.algos.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:51:42 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int		size;
	double	disorder;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	disorder = compute_disorder(size, *stack_a);
	if (disorder < 0.2)
		simple_sort(stack_a, stack_b, bench);
	else if (disorder < 0.5)
		medium_sort(stack_a, stack_b, bench);
	else
		complex_sort(stack_a, stack_b, bench);
}
