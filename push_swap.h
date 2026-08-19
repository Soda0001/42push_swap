/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odurmaz@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 13:24:11 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/19 13:35:02 by odurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

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