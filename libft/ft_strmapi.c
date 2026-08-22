/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:47:40 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:47:42 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
