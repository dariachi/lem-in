/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:37:19 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/10 15:58:22 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*cop;
	size_t		i;
	size_t		j;
	size_t		g;

	i = 0;
	g = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	cop = NULL;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[j - 1] == '\n' || s[j - 1] == ' ' || s[j - 1] == '\t')
		j--;
	if (j > i)
		cop = (char *)malloc(sizeof(char) * (j - i + 1));
	else
		cop = (char *)malloc(1);
	if (!cop)
		return (NULL);
	while (s[i] != '\0' && (i < j))
		cop[g++] = s[i++];
	cop[g] = '\0';
	return (cop);
}
