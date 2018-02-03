/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:09:22 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/07 11:09:24 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	len;
	size_t	j;
	size_t	d;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	d = s - i - 1;
	if (i < s)
	{
		while (src[j] && (d > 0))
		{
			dst[i] = src[j];
			i++;
			j++;
			d--;
		}
		dst[i] = '\0';
		return (len);
	}
	return (s + ft_strlen(src));
}
