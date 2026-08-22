/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:37:46 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:37:53 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ddest;
	const unsigned char	*ssrc;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	ddest = (unsigned char *) dest;
	ssrc = (const unsigned char *) src;
	i = n;
	if (dest > src)
	{
		while (i > 0)
		{
			i--;
			ddest[i] = ssrc[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
