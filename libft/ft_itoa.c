/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:04:55 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 15:31:04 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nlen(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n > 9)
	{
		while (n > 9)
		{
			i++;
			n = n / 10;
		}
	}
	i++;
	return (i);
}

static char		*ft_minstr(long int nbr, int i, char *ptr)
{
	nbr = -1 * nbr;
	ptr[0] = '-';
	while (--i > 0)
	{
		ptr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (ptr);
}

char			*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	nbr;

	nbr = n;
	i = ft_nlen(nbr);
	ptr = ft_strnew((size_t)i);
	if (ptr == NULL)
		return (NULL);
	if (nbr < 0)
		ptr = ft_minstr(nbr, i, ptr);
	else
		while (--i >= 0)
		{
			ptr[i] = n % 10 + '0';
			n = n / 10;
		}
	return (ptr);
}
