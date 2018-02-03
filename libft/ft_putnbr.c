/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:36:52 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 15:38:03 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printnb(int s)
{
	int		i;
	char	b[10];

	i = 0;
	if (s < 0)
	{
		ft_putchar('-');
		s *= (-1);
	}
	while (s)
	{
		b[i] = s % 10 + '0';
		s /= 10;
		i++;
	}
	while (i--)
		ft_putchar(b[i]);
}

void			ft_putnbr(int n)
{
	if (n != -2147483648)
	{
		if (n != 0)
			ft_printnb(n);
		else
			ft_putchar(48);
	}
	else
	{
		ft_putchar('-');
		ft_printnb(2147483);
		ft_printnb(648);
	}
}
