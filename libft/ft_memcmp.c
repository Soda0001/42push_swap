/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:37:05 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:37:08 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *p1, const void *p2, size_t num)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)p1;
	ptr2 = (const unsigned char *)p2;
	i = 0;
	while (i < num && ptr1[i] == ptr2[i])
		i++;
	if (i == num)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
