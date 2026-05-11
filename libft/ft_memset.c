/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:41:09 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/03 14:31:57 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) s;
	while (n > i)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*#include<stdio.h>

int main(void)
{
	char	str[50] = "hola mundo";
	
	ft_memset(str, '.', 3);
	printf("hola mundo ahora es : %s\n", str);
	return (0);
}*/
