/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:45:05 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/06 14:13:42 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*d;

	d = (void *)malloc(size);
	if (d == NULL)
		return (NULL);
	ft_memset(d, 0, size);
	return (d);
}
