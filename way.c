/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:27:31 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/01 18:27:34 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				encl_serch_ways2(t_all *all, t_relations **s, int x, t_truck *g)
{
	char		*z;
	t_relations	*p;

	if (x > 0)
		ft_copy(all, s, all->d);
	all->r = malloc(sizeof(t_relations));
	all->r->next = NULL;
	all->r->rel = ft_strdup(g->s);
	p = s[all->a];
	while (p->next)
		p = p->next;
	p->next = all->r;
	z = ft_strdup(g->s);
	serch_ways2(all, z, s);
	x++;
	free(z);
	return (x);
}

int				e_serch_ways22(t_all *all, t_relations **s, int x, t_truck *g)
{
	char		*z;
	t_relations	*p;

	if (x > 0)
		ft_copy(all, s, all->d);
	all->r = malloc(sizeof(t_relations));
	all->r->next = NULL;
	all->r->rel = ft_strdup(g->f);
	p = s[all->a];
	while (p->next)
		p = p->next;
	p->next = all->r;
	z = ft_strdup(g->f);
	serch_ways2(all, z, s);
	x++;
	free(z);
	return (x);
}

void			serch_ways2(t_all *all, char *way, t_relations **s)
{
	int			x;
	t_truck		*g;

	g = malloc(sizeof(t_truck));
	x = 0;
	g = all->truck1;
	all->d++;
	while (g)
	{
		if (ft_strcmp(way, g->f) == 0 && g->c_s == g->c_f - 1)
			x = encl_serch_ways2(all, s, x, g);
		if (ft_strcmp(way, g->s) == 0 && g->c_s - 1 == g->c_f)
			x = e_serch_ways22(all, s, x, g);
		g = g->next;
	}
	all->d--;
	free(g);
}

void			serch_ways(t_all *all, char *way, t_relations **s)
{
	t_truck		*u;
	int			x;

	u = malloc(sizeof(t_truck));
	u = all->truck1;
	all->d = 2;
	x = 0;
	while (u)
	{
		if (ft_strcmp(way, u->f) == 0 && u->c_s == u->c_f - 1)
			x = encl_serch_ways2(all, s, x, u);
		if (ft_strcmp(way, u->s) == 0 && u->c_s - 1 == u->c_f)
			x = e_serch_ways22(all, s, x, u);
		u = u->next;
	}
	free(u);
}
