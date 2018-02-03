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

int				three_next_f(t_all *all, t_relations **z)
{
	t_relations	*u1;

	ft_distance_truck(all);
	building_the_way(all, z);
	u1 = z[0];
	while (u1->next)
		u1 = u1->next;
	if (ft_strcmp(u1->rel, all->st) != 0)
		return (0);
	last_way(all, z);
	return (1);
}

int				next_next_main(t_all *all, char **s, char *str)
{
	t_tint		d[100];
	t_relations	**z;
	int			t;
	int			mas[all->ants];

	z = malloc(sizeof(t_relations *) * 500);
	str = s[all->i];
	if (check_links(str, all, s) == 0 || ft_position_def(all) == 0)
		return (0);
	if (three_next_f(all, z) == 0 || optimal_ways(all, d, z) == 0)
		return (0);
	if (start_end_way(all) == 0)
		return (1);
	flip_and_len_ways(all, d, z);
	t = 0;
	while (t < all->ants)
	{
		mas[t] = 1;
		t++;
	}
	write_str(s);
	move_ants(all, z, d, mas);
	return (1);
}
