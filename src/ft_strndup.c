/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasilio <abasilio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:47:03 by abasilio          #+#    #+#             */
/*   Updated: 2026/07/28 17:03:34 by abasilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strndup(const char *s, size_t n) //REVIEW - Should it be directly on libft.a?
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	dup[n] = '\0';
	while (s[i] != '\0' && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
