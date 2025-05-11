/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitagtm <vitagtm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:20:57 by vgetman           #+#    #+#             */
/*   Updated: 2025/05/11 18:28:43 by vitagtm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void *ft_free_word(char **total_words)
{
	int i;

	i = 0;
	while (total_words[i])
	{
		free(total_words[i]);
		i++;
	}
	free(total_words);
	return (NULL);
}

int ft_wordcount(char const *s, char c)
{
	size_t i;
	int wc;

	wc = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			wc++;
		}
		if (*s == c)
			i = 0;
		s++;
	}
	return (wc);
}

char **ft_split(char const *s, char c)
{
	int i;
	char **totalword;
	int start;
	int end;

	i = 0;
	start = 0;
	end = 0;
	totalword = ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!totalword)
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		totalword[i] = ft_substr(s, start, end - start);
		if (!totalword[i++])
			return (ft_free_word(totalword));
		start = end;
	}
	totalword[i] = NULL;
	return (totalword);
}
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *temp;
	size_t i;
	i = 0;
	temp = malloc(count * size);

	if (!temp)
		return (NULL);
	while (i < count * size)
	{
		temp[i++] = 0;
	}
	return (temp);
}