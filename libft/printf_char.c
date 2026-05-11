/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:33:46 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/14 20:03:02 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	printf_str(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = ft_strlen(s);
	write (1, s, i);
	return (i);
}
