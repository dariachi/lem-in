/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:41:55 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/01 18:41:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_distance_truck(t_all *all)
{
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		all->room2 = all->room1->next;
		while (all->room2)
		{
			if (ft_strcmp(all->room2->name, all->truck2->f) == 0)
				all->truck2->c_f = all->room2->count;
			else if (ft_strcmp(all->room2->name, all->truck2->s) == 0)
				all->truck2->c_s = all->room2->count;
			all->room2 = all->room2->next;
		}
		all->truck2 = all->truck2->next;
	}
	all->a = 0;
}

int				three_next_f(t_all *all, t_relations **z, char **s)
{
	t_relations	*u1;

	ft_distance_truck(all);
	if (building_the_way(all, z, s) == 2)
		return (2);
	u1 = z[0];
	while (u1->next)
		u1 = u1->next;
	if (ft_strcmp(u1->rel, all->st) != 0)
		return (0);
	last_way(all, z);
	return (1);
}

void			free_relations(t_all *all, t_relations **z)
{
	int			u;
	t_relations *d1;
	t_relations *d2;

	u = 0;
	while (u <= all->a)
	{
		d1 = z[u];
		if (d1 == NULL)
		{
			u++;
			if (u >= all->a)
				break ;
			continue ;
		}
		while (d1)
		{
			d2 = d1;
			d1 = d1->next;
			free(d2->rel);
			free(d2);
		}
		u++;
	}
	free(z);
}

int				ft_next_main_m(t_all *all, t_relations **z, char **s, t_tint *d)
{
	int			k;

	k = three_next_f(all, z, s);
	if (k == 0)
	{
		free_relations(all, z);
		return (0);
	}
	else if (k == 2)
	{
		free_relations(all, z);
		return (1);
	}
	if (optimal_ways(all, d, z) == 0)
	{
		free_relations(all, z);
		return (0);
	}
	if (start_end_way(all, s) == 0)
	{
		free_relations(all, z);
		return (1);
	}
	return (2);
}

int				next_next_main(t_all *all, char **s, char *str)
{
	t_tint		d[100];
	t_relations	**z;
	int			t;
	int			mas[all->ants];

	z = ft_creat_relations(all);
	str = s[all->i];
	if (str == NULL)
		return (ft_fre_str(z));
	if (check_links(str, all, s) == 0 || ft_position_def(all) == 0)
	{
		free_relations(all, z);
		return (0);
	}
	t = ft_next_main_m(all, z, s, d);
	if (t == 0 || t == 1)
		return (t);
	flip_and_len_ways(all, d, z, 0);
	value_in_one(mas, all);
	write_str(s);
	end_free(all, s);
	move_ants(all, z, d, mas);
	free_relations(all, z);
	return (1);
}
