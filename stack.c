/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:11:56 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/21 17:11:56 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_numeric_and_in_range(const char *str, long *out_val)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		i++;
	}
	*out_val = num * sign;
	return (1);
}

static int	has_duplicate(t_node *stack, int val)
{
	while (stack)
	{
		if (stack->content == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	process_token(t_node **stack, const char *token)
{
	long	long_val;
	int		val;

	if (!is_numeric_and_in_range(token, &long_val))
		return (0);
	val = ft_atoi(token);
	if (has_duplicate(*stack, val))
		return (0);
	insert_at_tail(stack, new_node(val));
	return (1);
}

static int	process_arg(t_node **stack, char *arg)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		if (tokens)
			free(tokens);
		return (0);
	}
	j = 0;
	while (tokens[j])
	{
		if (!process_token(stack, tokens[j]))
		{
			j = 0;
			while (tokens[j])
				free(tokens[j++]);
			free(tokens);
			return (0);
		}
		free(tokens[j]);
		j++;
	}
	free(tokens);
	return (1);
}

t_node	*initialize_stack(char **av, int ac, int start)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = start;
	while (i < ac)
	{
		if (!process_arg(&stack, av[i]))
		{
			free_stack(&stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
