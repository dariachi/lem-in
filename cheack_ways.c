/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:24:15 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 13:24:17 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				flip_and_len_ways(t_all *all, t_tint *d, t_relations **z,
									int len)
{
	t_relations	*d1;
	int			t;

	t = 0;
	all->jj = 0;
	while (d[t].i != -1)
	{
		if (flipping(z, d[t].i) == 0)
			return (0);
		t++;
	}
	while (d[all->jj].i != -1)
	{
		d1 = z[d[all->jj].i];
		len = 0;
		while (d1)
		{
			len++;
			d1 = d1->next;
		}
		d[all->jj].len = len - 1;
		all->jj++;
	}
	d[all->jj].len = 1000;
	return (1);
}

void			write_str(char **s)
{
	int c;

	c = 0;
	while (s[c] != NULL)
	{
		ft_putstr(s[c]);
		ft_putchar('\n');
		c++;
	}
	ft_putchar('\n');
}

void			last_way(t_all *all, t_relations **z)
{
	t_relations *k1;
	t_relations *p1;
	t_relations *s;
	int			a;

	a = 0;
	while (a <= all->a)
	{
		k1 = z[a];
		while (k1->next)
			k1 = k1->next;
		if (ft_strcmp(all->st, k1->rel) != 0)
		{
			p1 = z[a];
			while (p1)
			{
				s = p1;
				p1 = p1->next;
				free(s->rel);
				free(s);
			}
			z[a] = NULL;
		}
		a++;
	}
}
