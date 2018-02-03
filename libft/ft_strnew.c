/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:50:25 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/10 15:55:18 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*d;

	d = (char *)malloc(size + 1);
	if (d == NULL)
		return (NULL);
	ft_memset(d, '\0', (size + 1));
	return (d);
}
