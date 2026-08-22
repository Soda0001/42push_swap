/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:06:29 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 17:06:35 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 && *s1 == *s2)
	{
		i++;
		s1++;
		s2++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
