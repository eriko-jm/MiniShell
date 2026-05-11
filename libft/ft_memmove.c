/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:51:21 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/03 15:56:36 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest1;
	const char	*src1;
	size_t		i;

	dest1 = (char *) dest;
	src1 = (const char *) src;
	if (dest1 == src1 || n == 0)
		return (dest);
	if (dest1 < src1)
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	return (dest);
}
