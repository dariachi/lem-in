/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:26:59 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 15:25:54 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*c;
	size_t		i;

	c = NULL;
	i = 0;
	if (s)
		c = ft_strnew(len);
	if (c == NULL)
		return (NULL);
	while (len > i)
		c[i++] = s[start++];
	return (c);
}
