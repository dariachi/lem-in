/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:02:37 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/16 15:27:54 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**res;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((res = (char**)malloc(sizeof(char*) * (ft_wcount(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		if (i == 0 || (s[i] != c && s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j] = ft_strsub(s, (unsigned int)start, (size_t)i - start + 1);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}
