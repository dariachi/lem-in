/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:14:44 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/07 11:14:47 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	int		i;
	char	s2;

	i = 0;
	if (s && f)
	{
		r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!r)
			return (NULL);
		while (*s)
		{
			s2 = f(*s++);
			if (s2)
				r[i++] = s2;
		}
		r[i] = '\0';
		return (r);
	}
	return (NULL);
}
