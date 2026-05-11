/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:38:17 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/10 19:13:47 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_contador(char const *s, char c)
{
	int		new_str;
	size_t	cont;
	size_t	i;

	i = 0;
	cont = 0;
	new_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && new_str == 0)
		{
			new_str = 1;
			cont++;
		}
		else if (s[i] == c && new_str == 1)
			new_str = 0;
		i++;
	}
	return (cont);
}

static size_t	ft_wordlen(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static void	free_all(char **arr, size_t j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;
	size_t	iter[2];

	if (!s)
		return (NULL);
	words = ft_contador(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	iter[0] = ((iter[1] = 0), 0);
	while (s[iter[0]] && iter[1] < words)
	{
		if (s[iter[0]] != c)
		{
			arr[iter[1]] = ft_substr(s, iter[0], ft_wordlen(s, c, iter[0]));
			if (!arr[iter[1]])
				return (free_all(arr, iter[1]), NULL);
			iter[0] += ft_wordlen(s, c, iter[0]);
			iter[1]++;
		}
		else
			iter[0]++;
	}
	return ((arr[iter[1]] = NULL), arr);
}
