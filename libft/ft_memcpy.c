/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:37:18 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:37:36 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ddest;
	const unsigned char	*ssrc;
	size_t				i;

	ddest = (unsigned char *) dest;
	ssrc = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (dest);
}
