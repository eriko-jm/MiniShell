/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:28:05 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/03 16:44:52 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	i = 0;
	dest1 = (char *)dest;
	src1 = (const char *)src;
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

/*#include<stdio.h>

int	main (void)
{
	char	dest[50];
	char	src[50] = "hola que tal?";
	
	ft_memcpy(dest, src, 8);
	
	printf("se ha copiado: %s\n", dest);
	return (0);
}*/
