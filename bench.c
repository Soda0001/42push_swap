/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/30 16:50:00 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/31 01:32:22 by alterzi         ###   ########.fr        */
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

// static void	ft_putnbr_fd(int n, int fd)
// {
// 	char	buf[16];
// 	int		i;

// 	i = 15;
// 	buf[i] = '\0';
// 	if (n == 0)
// 	{
// 		write(fd, "0", 1);
// 		return ;
// 	}
// 	while (n > 0)
// 	{
// 		buf[--i] = (n % 10) + '0';
// 		n = n / 10;
// 	}
// 	write(fd, buf + i, 15 - i);
// }

static void	put_op_line(const char *label, int value)
{
	ft_putstr_fd((char *) label, 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd(" ", 2);
}

static const char	*strat_name(t_strategy s)
{
	if (s == STRAT_SIMPLE)
		return ("Simple");
	if (s == STRAT_MEDIUM)
		return ("Medium");
	if (s == STRAT_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

void	print_bench(t_strategy strategy, double disorder, t_bench *bench)
{
	int	pct;

	if (!bench)
		return ;
	pct = (int)(disorder * 10000);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct / 100, 2);
	ft_putstr_fd(".", 2);
	if (pct % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(pct % 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *) strat_name(strategy), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
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
