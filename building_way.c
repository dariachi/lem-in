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

void		enclosed_bulid_way(t_all *all, t_relations **z,
					char *truck, char *current_name)
{
	if (current_name != NULL)
	{
		all->d = 1;
		ft_copy(all, z, all->d);
	}
	all->r = malloc(sizeof(t_relations));
	all->r->rel = ft_strdup(truck);
	z[all->a]->next = all->r;
	serch_ways(all, truck, z);
	current_name = truck;
	truck = NULL;
}

void		building_the_way(t_all *all, t_relations **z)
{
	char	*truck;
	char	*current_name;

	truck = NULL;
	current_name = NULL;
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
			enclosed_bulid_way(all, z, truck, current_name);
		all->truck2 = all->truck2->next;
	}
}

int		start_end_way(t_all *all)
{
	int	zz;

	zz = 0;
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		if ((ft_strcmp(all->truck2->f, all->st) == 0 ||
			ft_strcmp(all->truck2->f, all->en) == 0) &&
			(ft_strcmp(all->truck2->s, all->st) == 0 ||
				ft_strcmp(all->truck2->s, all->en) == 0))
		{
			while (all->ants != zz)
			{
				ft_putchar('L');
				ft_putnbr(zz + 1);
				ft_putchar('-');
				ft_putstr(all->en);
				zz++;
			}
			ft_putchar('\n');
			return (0);
		}
		all->truck2 = all->truck2->next;
	}
	return (1);
}

// ft_ddd()
// {
// 	int ddd = 0;
// 	while (all->t[ddd].i > -1)
// 	{
// 		d[ddd].i = all->t[ddd].i;
// 		ddd++;
// 	} 
// 	d[ddd].i = -1;
// 	f1 = o;
// }

int		optimal_ways(t_all *all, t_tint *d, t_relations **z)
{
	int	f1;
	int h;

	f1= -1;
	h = 0;
	while(h < all->a)
	{
		while (z[h] == NULL && all->a >= h)
			h++;
		if (h > all->a)
			return (0);
		inter(all, z, h);
		int o = 0;
		while (all->t[o].i > -1)
			o++;
		if (f1 < o)
		{
			int ddd = 0;
			while (all->t[ddd].i > -1)
			{
				d[ddd].i = all->t[ddd].i;
				ddd++;
			} 
			d[ddd].i = -1;
			f1 = o;
		}
		h++;
	}
	if (all->a == 0)
	{
		d[0].i = 0;
		d[1].i = -1;
	}
	return (1);
}
