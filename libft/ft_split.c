/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedeniz <sedeniz@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:39:38 by sedeniz           #+#    #+#             */
/*   Updated: 2026/08/08 16:39:47 by sedeniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		word_count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word_count);
}

static size_t	find_word_len(char const *s, char c)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	word_len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		word_len++;
		i++;
	}
	return (word_len);
}

static char	**free_all(char **splitd, int count)
{
	while (count)
	{
		count--;
		free(splitd[count]);
	}
	free(splitd);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	size_t	len;
	char	**splitd;

	i = 0;
	j = 0;
	word = count_words(s, c);
	splitd = malloc(sizeof(char *) * (word + 1));
	if (!splitd)
		return (NULL);
	while (i < word)
	{
		while (s[j] && s[j] == c)
			j++;
		len = find_word_len(&s[j], c);
		splitd[i] = ft_substr(s, j, len);
		if (!splitd[i])
			return (free_all(splitd, i));
		j += len;
		i++;
	}
	splitd[i] = NULL;
	return (splitd);
}
