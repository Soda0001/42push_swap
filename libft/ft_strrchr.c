/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:17:23 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 17:21:54 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		_char;
	const char	*last;

	_char = (char)c;
	last = NULL;
	while (*str)
	{
		if (*str == _char)
			last = str;
		str++;
	}
	if (*str == _char)
		return ((char *)str);
	return ((char *)last);
}
