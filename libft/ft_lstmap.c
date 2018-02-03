/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:09:58 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/08 14:51:19 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((ret = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	ret = f(lst);
	ret->next = ft_lstmap(lst->next, f);
	return (ret);
}
