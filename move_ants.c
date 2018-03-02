/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:07:43 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 14:07:45 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			embedded_loop2(t_all *all, t_tint *d, int *mas)
{
	int		found;

	all->o = 0;
	found = 0;
	while (all->d1)
	{
		if (all->d1->r == 0 && all->o == 0 && all->aant <= all->ants &&
			d[all->jj].len - d[0].len < all->ants)
		{
			ft_write_ants(all);
			all->d1->r = all->aant;
			if (!ft_strcmp(all->d1->rel, all->en))
			{
				mas[all->aant - 1] = 0;
				all->d1->r = 0;
			}
			found = 1;
		}
		else if (all->d1->r != 0)
			all->o = all->d1->r;
		if (found == 1)
			break ;
		all->d1 = all->d1->next;
	}
	return (found);
}

void		ft_emb(t_all *all, t_relations **z, t_tint *d, int *mas)
{
	all->jj = 0;
	while (d[all->jj].i != -1)
	{
		all->d1 = z[d[all->jj].i]->next;
		all->found = embedded_loop2(all, d, mas);
		if (all->found)
			break ;
		all->jj++;
	}
}

void		embedded_cycle(t_all *all, t_relations **z, t_tint *d, int *mas)
{
	all->aant = 1;
	all->jj = 0;
	while (all->aant - 1 < all->ants)
	{
		all->jj = 0;
		all->found = 0;
		while (mas[all->aant - 1] == 0)
			all->aant++;
		while (d[all->jj].i != -1)
		{
			all->d1 = z[d[all->jj].i]->next;
			all->found = embedded_loop(all, mas);
			if (all->found)
				break ;
			all->jj++;
		}
		if (all->found == 0)
			ft_emb(all, z, d, mas);
		all->aant++;
	}
}

void		move_ants_c(t_all *all, t_tint *d)
{
	all->cof.k = 0;
	all->cof.c = 0;
	while (d[all->cof.k].i != -1)
	{
		all->cof.x = d[all->cof.c].i;
		all->cof.len = d[all->cof.c].len;
		if (d[all->cof.k].len < all->cof.len)
		{
			d[all->cof.c].len = d[all->cof.k].len;
			d[all->cof.k].len = all->cof.len;
			d[all->cof.c].i = d[all->cof.k].i;
			d[all->cof.k].i = all->cof.x;
			all->cof.c = all->cof.k;
		}
		all->cof.k++;
	}
}

void		move_ants(t_all *all, t_relations **z, t_tint *d, int *mas)
{
	all->cof.u = 1;
	all->cof.x = 0;
	all->cof.len = 0;
	all->cof.y = 1;
	all->cof.c = 0;
	while (d[all->cof.y].i != -1)
		all->cof.y++;
	all->cof.u = 1;
	all->cof.x = d[0].i;
	all->cof.len = d[0].len;
	all->cof.c = 0;
	while (d[all->cof.u].i != -1)
	{
		move_ants_c(all, d);
		all->cof.u++;
	}
	all->cof.u = 0;
	while (are_there_any_ants(mas, all->ants))
	{
		embedded_cycle(all, z, d, mas);
		write(1, "\n", 1);
	}
}
