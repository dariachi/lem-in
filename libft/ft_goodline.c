/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goodline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:45:56 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/16 14:49:15 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_goodline(char *c)
{
	int		i;
	int		j;
	char	*d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(c) + 1));
	j = 0;
	i = 0;
	if (c == NULL)
		return (NULL);
	while (c[i] != '\0')
	{
		while (c[i] == ' ' || c[i] == '\t')
		{
			if (c[i - 1] != ' ' && c[i - 1] != '\t' && (i != 0))
			{
				d[j] = ' ';
				i++;
				j++;
			}
			i++;
		}
		d[j++] = c[i++];
	}
	d[j] = '\0';
	return (d);
}
