/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:27:33 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/10 11:12:25 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;
	size_t	max_size;

	i = 0;
	max_size = (size_t) - 1;
	if (!count || !size)
	{
		result = malloc(0);
		return (result);
	}
	if (count > max_size / size)
		return (NULL);
	result = malloc(size * count);
	if (!result)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return (result);
}
