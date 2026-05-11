/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:42:08 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/03 17:36:08 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)s;
	while (s2[i] != '\0')
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s2[i]);
	return (NULL);
}

/* #include<stdio.h>

int main (void)
{
	char	str[] = "hola que tal";
	char	c = '\0';
	char	*puta;
	puta = ft_strchr(str, c);
	printf("%s", puta);
	return(0);
} */
