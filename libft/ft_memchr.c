/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 08:48:21 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/10 10:15:36 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*pointer;
	unsigned char		cha;
	size_t				i;

	pointer = (const unsigned char *)ptr;
	cha = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*pointer == cha)
			return ((void *)pointer);
		pointer++;
		i++;
	}
	return (NULL);
}
