/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:43:33 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/10 15:09:05 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;
	unsigned char	k;
	size_t			i;

	k = (unsigned char)c;
	b = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(b + i) == k)
		{
			return (b + i);
		}
		++i;
	}
	return (NULL);
}
