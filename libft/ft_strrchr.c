/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:03:00 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/03 17:05:42 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		i;

	s2 = (char *)s;
	i = 0;
	while (s2[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
		return (&s2[i]);
	i -= 1;
	while (i >= 0)
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s2[i]);
		i--;
	}
	return (NULL);
}

/* #include<stdio.h>

int main (void)
{
	char	str[] = "hola que tal??";
	char	c = 'x';
	char	*puta;
	puta = ft_strrchr(str, c);
	printf("%s", puta);
	return(0);
} */
