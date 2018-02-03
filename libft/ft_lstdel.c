/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:26:11 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 16:59:20 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *el;
	t_list *tmp;

	el = *alst;
	while (el != NULL)
	{
		tmp = el->next;
		del(el->content, el->content_size);
		free(el);
		el = NULL;
		el = tmp;
	}
	*alst = NULL;
}
