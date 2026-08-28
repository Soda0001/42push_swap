/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple_sort.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alterzi <alterzi@student.42istanbul.com.tr#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/28 19:12:13 by alterzi          #+#    #+#              */
/*   Updated: 2026/08/28 19:19:18 by alterzi         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_rank(t_node *stack, int content)
{
	int		rank;
	t_node	*cur;

	rank = 0;
	cur = stack;
	while (cur)
	{
		if (cur->content < content)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

/*
** a yigini icindeki en kucuk elemani bulur ve degerini dondurur.
*/

static int	find_min(t_node *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

/*
** a yigini icinde verilen deger hangi indekste, bul ve dondur.
*/

static int	find_pos(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack->content != value)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

/*
** Elemani tepeye en ucuz yoldan getirir:
** Eger eleman yigin yarısının ustündeyse ra,
** alttaysa rra kullanilir.
*/

static void	move_to_top(t_node **stack_a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			op_rra(stack_a);
	}
}

/*
** Basit algoritma: secmeli (selection) siralama.
** Her adimda a icindeki en kucuk degeri bulur, en ucuz rotasyonla
** tepeye getirir ve pb ile b'ye gonderir. Boylece b, en kucukten
** en buyuge dogru alttan uste dogru siralanmis olur. Sonunda
** hepsini pa ile geri almak b'yi tersine cevirir ve a, en kucuk
** tepede olacak sekilde tamamen sirali hale gelir.
** n eleman icin n kez arama + rotasyon -> O(n^2) islem.
*/

void	simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	n;
	int	i;
	int	pos;
	int	size;
	int	min;

	if (try_sort_small(stack_a))
		return ;
	n = stack_size(*stack_a);
	i = 0;
	while (i < n)
	{
		min = find_min(*stack_a);
		size = stack_size(*stack_a);
		pos = find_pos(*stack_a, min);
		move_to_top(stack_a, pos, size);
		op_pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		op_pa(stack_a, stack_b);
}
