/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:34:00 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/14 20:03:14 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_int(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (int_len(nb));
}

static void	putnbr_uns_fd(unsigned int n, int fd)
{
	if (n > 9)
		putnbr_uns_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static int	uns_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	print_uns(unsigned int nb)
{
	putnbr_uns_fd(nb, 1);
	return (uns_len(nb));
}
