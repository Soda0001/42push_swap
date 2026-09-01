/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 18:22:52 by alterzi          #+#    #+#              */
/*   Updated: 2026/09/01 15:33:39 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	track_op(t_bench *bench, t_op op)
{
	if (bench && op >= 0 && op < OP_COUNT)
	{
		bench->counts[op]++;
		bench->total_ops++;
	}
}

static void	put_op_line(const char *label, int value)
{
	ft_putstr_fd((char *) label, 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd(" ", 2);
}

static void	print_strategy_info(t_strategy strategy, double disorder)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == STRAT_SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (strategy == STRAT_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (strategy == STRAT_COMPLEX)
		ft_putstr_fd("Complex / O(nlogn)\n", 2);
	else
	{
		if (disorder < 0.2)
			ft_putstr_fd("Adaptive / O(n²)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("Adaptive / O(n√n)\n", 2);
		else
			ft_putstr_fd("Adaptive / O(nlogn)\n", 2);
	}
}

static void	print_header(t_strategy strategy, double disorder, t_bench *bench)
{
	int	pct;

	pct = (int)(disorder * 10000);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putstr_fd(".", 2);
	if (pct % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(pct % 100, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy_info(strategy, disorder);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_strategy strategy, double disorder, t_bench *bench)
{
	if (!bench)
		return ;
	print_header(strategy, disorder, bench);
	put_op_line("[bench] sa: ", bench->counts[OP_SA]);
	put_op_line("sb: ", bench->counts[OP_SB]);
	put_op_line("ss: ", bench->counts[OP_SS]);
	put_op_line("pa: ", bench->counts[OP_PA]);
	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(bench->counts[OP_PB], 2);
	ft_putstr_fd("\n", 2);
	put_op_line("[bench] ra: ", bench->counts[OP_RA]);
	put_op_line("rb: ", bench->counts[OP_RB]);
	put_op_line("rr: ", bench->counts[OP_RR]);
	put_op_line("rra: ", bench->counts[OP_RRA]);
	put_op_line("rrb: ", bench->counts[OP_RRB]);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(bench->counts[OP_RRR], 2);
	ft_putstr_fd("\n", 2);
}
