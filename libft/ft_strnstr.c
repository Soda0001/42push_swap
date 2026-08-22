/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:09:46 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 17:09:48 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < n)
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && to_find[j] && (i + j) < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
