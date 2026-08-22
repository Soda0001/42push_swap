/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:26:25 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 14:26:47 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == 45 || ptr[i] == 43)
	{
		if (ptr[i] == 45)
			sign = -sign;
		i++;
	}
	while (ptr[i] && ptr[i] >= 48 && ptr[i] <= 57)
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (result * sign);
}
