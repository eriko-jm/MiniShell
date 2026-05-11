/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:04:25 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/10 12:45:09 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aux(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	start;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && aux(s1[start], set) == 1)
		start++;
	len = ft_strlen(s1);
	while (len > start && aux(s1[len - 1], set) == 1)
		len--;
	str = malloc(sizeof(char) * ((len - start) + 1));
	if (!str)
		return (NULL);
	while (len > start)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>

int main ()
{
	char	*s1 = "hola que tal";
	char	*s2 = "alo";
	char	*ptr;
	ptr = ft_strtrim(s1, s2);

	printf("%d\n", ft_strlen(s1));
	printf("%s\n", ptr);
	return (0);
}*/
