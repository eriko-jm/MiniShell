/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:29:22 by joaseque          #+#    #+#             */
/*   Updated: 2026/03/18 20:29:11 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int c)
{
	int		i;
	char	*s2;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
