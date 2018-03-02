/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_main2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:18:25 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 13:18:28 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_relations		**ft_creat_relations(t_all *all)
{
	t_relations	**z;
	int			t;

	all->max_lines = 500;
	z = malloc(sizeof(t_relations *) * all->max_lines);
	t = 0;
	while (t < all->max_lines)
		z[t++] = NULL;
	return (z);
}

void			value_in_one(int *mas, t_all *all)
{
	int			t;

	t = 0;
	while (t < all->ants)
	{
		mas[t] = 1;
		t++;
	}
}

void			end_free(t_all *all, char **s)
{
	int			u;
	t_truck		*tr;

	while (all->truck1)
	{
		tr = all->truck1;
		all->truck1 = all->truck1->next;
		free(tr->s);
		free(tr->f);
		free(tr);
	}
	u = 0;
	while (s[u])
	{
		free(s[u]);
		u++;
	}
}

void			malloc_room3(t_all *all)
{
	all->room3 = malloc(sizeof(t_node));
	all->room3->next = NULL;
}

int				ft_fre_str(t_relations **z)
{
	free(z);
	return (0);
}
