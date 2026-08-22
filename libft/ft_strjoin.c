/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:43:35 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:43:36 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	final_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		final_str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	final_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (final_str);
}
