/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:16 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/04 22:11:39 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s1;

	i = 0;
	s1 = (char *)big;
	if (little[0] == '\0')
		return (&s1[i]);
	while (i < len && s1[i] != '\0')
	{
		j = 0;
		k = i;
		while (s1[k] == little[j] && s1[k] != '\0')
		{
			k++;
			j++;
			if (little[j] == '\0' && k <= len)
				return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
