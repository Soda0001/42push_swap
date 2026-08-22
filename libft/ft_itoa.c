/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:30:35 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 14:31:22 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	fill_num_str(int n, char *num_str)
{
	long	num;
	int		len;

	num = n;
	if (num == 0)
	{
		num_str[0] = '0';
		num_str[1] = '\0';
		return ;
	}
	len = count_len(num);
	num_str[len] = '\0';
	if (num < 0)
	{
		num = -num;
		num_str[0] = '-';
	}
	while (num > 0)
	{
		num_str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		len;

	len = count_len(n);
	num_str = malloc(sizeof(char) * (len + 1));
	if (!num_str)
		return (NULL);
	fill_num_str(n, num_str);
	return (num_str);
}
