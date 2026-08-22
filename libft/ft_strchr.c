/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:40:01 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:40:53 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	c;

	c = (char)ch;
	while (*str != c && *str)
		str++;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
