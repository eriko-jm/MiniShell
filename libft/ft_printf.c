/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:55:06 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/14 20:03:25 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	formats(va_list vars, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += printf_char(va_arg(vars, int));
	else if (c == 's')
		count += printf_str(va_arg(vars, char *));
	else if (c == 'd' || c == 'i')
		count += print_int(va_arg(vars, int));
	else if (c == 'u')
		count += print_uns(va_arg(vars, unsigned int));
	else if (c == 'x')
		count += print_hex_low(va_arg(vars, unsigned int));
	else if (c == 'X')
		count += print_hex_upp(va_arg(vars, unsigned int));
	else if (c == 'p')
		count += print_ptr(va_arg(vars, void *));
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	vars;
	int		i;
	int		count;

	va_start(vars, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += formats(vars, str[i]);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(vars);
	return (count);
}
