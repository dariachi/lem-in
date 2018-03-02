/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_way2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:08:07 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 18:08:08 by dchirkin         ###   ########.fr       */
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
	all->r->next = NULL;
	all->r->rel = ft_strdup(truck);
	z[all->a]->next = all->r;
	serch_ways(all, truck, z);
}

int			ft_build(t_all *all, char *truck, t_relations **z, char **s)
{
	if (all->current_name > 0)
	{
		all->d = 1;
		ft_copy(all, z, all->d);
	}
	all->r = malloc(sizeof(t_relations));
	all->r->rel = ft_strdup(truck);
	all->r->next = NULL;
	z[all->a]->next = all->r;
	if ((ft_strcmp(all->truck2->f, all->en) == 0 &&
		ft_strcmp(all->truck2->s, all->st) == 0)
		|| (ft_strcmp(all->truck2->f, all->st) == 0 &&
			ft_strcmp(all->truck2->s, all->en) == 0))
	{
		free(truck);
		start_end_way(all, s);
		return (2);
	}
	else
		serch_ways(all, truck, z);
	return (1);
}

int			ft_write_an(int zz, char *en)
{
	ft_putchar('L');
	ft_putnbr(zz + 1);
	ft_putchar('-');
	ft_putstr(en);
	ft_putchar(' ');
	zz++;
	return (zz);
}
