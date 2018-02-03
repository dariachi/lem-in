/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:40:35 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 17:09:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*l;
	size_t	i;
	size_t	j;
	char	*b;

	l = (char *)little;
	b = (char *)big;
	i = 0;
	j = 0;
	if (ft_strlen(l) == 0)
		return (b);
	while (b[j])
	{
		while (b[j + i] == l[i])
		{
			if (i == ft_strlen(l) - 1)
				return (&b[j]);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
