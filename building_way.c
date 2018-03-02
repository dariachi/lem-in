/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:47:55 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/01 18:47:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				building_the_way(t_all *all, t_relations **z, char **s)
{
	char		*truck;

	truck = NULL;
	all->current_name = 0;
	all->r = malloc(sizeof(t_relations));
	all->r->rel = ft_strdup(all->en);
	z[all->a] = all->r;
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		if (ft_strcmp(all->truck2->f, all->en) == 0)
			truck = ft_strdup(all->truck2->s);
		if (ft_strcmp(all->truck2->s, all->en) == 0)
			truck = ft_strdup(all->truck2->f);
		if (truck && truck[0] != '\0')
		{
			if (ft_build(all, truck, z, s) == 2)
				return (2);
			all->current_name = 1;
			free(truck);
			truck = NULL;
		}
		all->truck2 = all->truck2->next;
	}
	return (1);
}

int				start_end_way(t_all *all, char **s)
{
	all->tt = 0;
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		if ((ft_strcmp(all->truck2->f, all->st) == 0 ||
			ft_strcmp(all->truck2->f, all->en) == 0) &&
			(ft_strcmp(all->truck2->s, all->st) == 0 ||
				ft_strcmp(all->truck2->s, all->en) == 0))
		{
			write_str(s);
			while (all->ants != all->tt)
				all->tt = ft_write_an(all->tt, all->en);
			ft_putchar('\n');
			all->jj = 0;
			while (s[all->jj])
			{
				free(s[all->jj]);
				all->jj++;
			}
			return (0);
		}
		all->truck2 = all->truck2->next;
	}
	return (1);
}

int				copy_way(t_all *all, t_tint *d, int o)
{
	int			ddd;

	ddd = 0;
	while (all->t[ddd].i > -1)
	{
		d[ddd].i = all->t[ddd].i;
		ddd++;
	}
	d[ddd].i = -1;
	return (o);
}

int				ft_intersection_loop(t_all *all, t_tint *d,
					t_relations **z, int m)
{
	int			h;
	int			f1;
	int			o;

	f1 = -1;
	h = 0;
	while (h < all->a)
	{
		while (z[h] == NULL && all->a >= h)
			h++;
		if (h > all->a && m == 0)
			return (0);
		else if (h > all->a)
			break ;
		inter(all, z, h);
		o = 0;
		while (all->t[o].i > -1)
			o++;
		if (f1 < o)
			f1 = copy_way(all, d, o);
		m++;
		h++;
	}
	return (1);
}

int				optimal_ways(t_all *all, t_tint *d, t_relations **z)
{
	int			h;
	t_relations	*d1;

	h = 0;
	while (all->a > h)
	{
		d1 = z[h];
		while (d1)
			d1 = d1->next;
		h++;
	}
	if (ft_intersection_loop(all, d, z, 0) == 0)
		return (0);
	if (all->a == 0)
	{
		d[0].i = 0;
		d[1].i = -1;
	}
	return (1);
}
