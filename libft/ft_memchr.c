/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:22:53 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/04 19:52:06 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *) s;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}

/*int main(void) 
{
    const char src[] = "Hola mundo";
    size_t size = 9;
    char *ptr = ft_memchr(src, '\0', size);

    if (ptr != NULL) {
		printf("El carácter '\\0' se encontró en la posición: %ld\n", ptr - src);
    } else {
        printf("No se encontró el carácter '\\0'.\n");
    }

    return 0;
}*/
