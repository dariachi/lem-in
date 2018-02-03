/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:00:18 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/09 17:26:27 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	l = (char *)lit;
	b = (char *)big;
	j = 0;
	if (ft_strlen(l) == 0)
		return (b);
	while ((b[j] != '\0') && (len != j))
	{
		i = 0;
		if (b[j] == l[i])
		{
			while (b[j + i] == l[i] && ((j + i) < len) && b[j + i] != '\0')
				i++;
			if (i == (ft_strlen(l)))
				return (&b[j]);
		}
		j++;
	}
	return (NULL);
}
