/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:04:14 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 16:04:16 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_relations		*ft_malloc(char *str)
{
	t_relations	*s;

	s = malloc(sizeof(t_relations));
	s->next = NULL;
	s->rel = ft_strdup(str);
	s->r = 0;
	return (s);
}

void			ft_free(t_relations *d)
{
	free(d->next->rel);
	free(d->next);
	d->next = NULL;
}

void			mal_free(t_rel *a, t_relations **s, int i)
{
	while (a->d1->next)
	{
		a->c = a->d1;
		a->d1 = a->d1->next;
	}
	a->d4 = ft_malloc(a->d1->rel);
	while (a->d3->next)
		a->d3 = a->d3->next;
	a->d3->next = a->d4;
	free(a->d1->rel);
	free(a->d1);
	a->c->next = NULL;
	a->d1 = NULL;
	a->d1 = s[i];
}

int				flipping(t_relations **s, int i)
{
	t_rel a;

	a.d1 = s[i];
	while (a.d1 && a.d1->next && a.d1->next->next)
		a.d1 = a.d1->next;
	a.d2 = ft_malloc(a.d1->next->rel);
	ft_free(a.d1);
	a.d3 = a.d2;
	a.d1 = s[i];
	while (a.d1->next)
		mal_free(&a, s, i);
	a.d4 = ft_malloc(a.d1->rel);
	while (a.d3->next)
		a.d3 = a.d3->next;
	a.d3->next = a.d4;
	free(a.c->rel);
	free(a.c);
	s[i] = NULL;
	s[i] = a.d2;
	return (1);
}
