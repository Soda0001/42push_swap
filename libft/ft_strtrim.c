/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:22:16 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 17:22:19 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char const *set)
{
	int	start;
	int	j;

	start = 0;
	while (s1[start])
	{
		j = 0;
		while (s1[start] != set[j] && set[j])
			j++;
		if (!set[j])
			break ;
		start++;
	}
	return (start);
}

static int	ft_find_end(char const *s1, char const *set, int start)
{
	int	j;
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= start)
	{
		j = 0;
		while (s1[end] != set[j] && set[j])
		{
			j++;
		}
		if (!set[j])
			break ;
		end--;
	}
	return (end);
}

static void	fill_trimmed_str(char const *s1, const char *set, char *trimmed_str)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, start);
	while (start <= end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		trimmed_len;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, start);
	trimmed_len = end - start + 1;
	trimmed_str = malloc(sizeof(char) * (trimmed_len + 1));
	if (!trimmed_str)
		return (NULL);
	fill_trimmed_str(s1, set, trimmed_str);
	return (trimmed_str);
}
