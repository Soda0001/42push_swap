/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:24:11 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 17:17:24 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

/*
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;
*/

/* Swap operations*/
void	op_sa(t_node **head);
void	op_sb(t_node **head);
void	op_ss(t_node **head_a, t_node **head_b);

/* Push operations */
void	op_pa(t_node **head_a, t_node **head_b);
void	op_pb(t_node **head_a, t_node **head_b);

/* Rotate operations */
void	op_ra(t_node **head_a);
void	op_rb(t_node **head_b);
void	op_rra(t_node **head_a);
void	op_rrb(t_node **head_b);
void	op_rr(t_node **head_a, t_node **head_b);
void	op_rrr(t_node **head_a, t_node **head_b);

#endif