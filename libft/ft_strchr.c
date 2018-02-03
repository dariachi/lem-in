/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:04:38 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 14:55:27 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*b;

	b = (unsigned char *)s;
	i = 0;
	while (b[i] != c && b[i] != '\0')
		i++;
	if (b[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)&b[i]);
}
