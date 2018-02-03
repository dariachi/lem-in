/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:47:45 by dchirkin          #+#    #+#             */
/*   Updated: 2017/02/23 14:51:55 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*b;
	size_t		k;
	size_t		i;
	size_t		j;

	k = 0;
	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	if (s1 || s2 || (s1 && s2))
		k = (ft_strlen(s1) + ft_strlen(s2));
	b = (char *)malloc(sizeof(char) * (k + 1));
	if (b == NULL)
		return (NULL);
	while (s1[i] != '\0')
		b[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		b[j++] = s2[i++];
	b[j] = '\0';
	return (b);
}
