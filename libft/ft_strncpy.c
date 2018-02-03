/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:28:48 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/10 15:25:02 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	if (len)
	{
		while (*src != '\0' && len > 0)
		{
			*s++ = *src++;
			len--;
		}
		while (len > 0)
		{
			*s++ = '\0';
			len--;
		}
	}
	return (&dst[0]);
}
