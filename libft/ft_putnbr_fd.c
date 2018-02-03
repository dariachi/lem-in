/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:28:32 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 15:31:44 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printnb(int s, int fd)
{
	int		i;
	char	b[10];

	i = 0;
	if (s < 0)
	{
		ft_putchar_fd('-', fd);
		s *= (-1);
	}
	while (s)
	{
		b[i] = s % 10 + '0';
		s /= 10;
		i++;
	}
	while (i--)
		ft_putchar_fd(b[i], fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
	{
		if (n != 0)
			ft_printnb(n, fd);
		else
			ft_putchar_fd(48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_printnb(2147483, fd);
		ft_printnb(648, fd);
	}
}
