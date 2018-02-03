/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:36:21 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/07 11:18:11 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;
	unsigned int	j;
	char			s2;

	i = 0;
	j = 0;
	if (s && f)
	{
		r = (char *)malloc(ft_strlen(s) + 1);
		if (!r)
			return (NULL);
		while (s[i] != '\0')
		{
			s2 = s[i];
			if (f(i, s2))
				r[j++] = f(i, s[i]);
			i++;
		}
		r[j] = '\0';
		return (r);
	}
	return (NULL);
}
