/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:29:44 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 18:29:46 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		copy_ther_row(t_all *all, t_rel *a, int tumba)
{
	a->d3 = malloc(sizeof(t_relations));
	a->d4 = a->d3;
	all->m = 0;
	all->t[all->m].i = tumba;
	all->m++;
	a->d4->rel = ft_strdup(a->d1->rel);
	a->d4->next = NULL;
	a->d1 = a->d1->next;
	while (a->d1)
	{
		a->d2 = malloc(sizeof(t_relations));
		a->d2->next = NULL;
		a->d2->rel = ft_strdup(a->d1->rel);
		while (a->d4->next)
			a->d4 = a->d4->next;
		a->d4->next = a->d2;
		a->d1 = a->d1->next;
	}
}

void		add_elements(t_rel *a, int z, t_all *all)
{
	while (a->d1 && z != -1)
	{
		if (ft_strcmp(a->d1->rel, all->en) == 0 ||
			ft_strcmp(a->d1->rel, all->st) == 0)
		{
			a->d1 = a->d1->next;
			continue;
		}
		a->d2 = malloc(sizeof(t_relations));
		a->d2->next = NULL;
		a->d2->rel = ft_strdup(a->d1->rel);
		while (a->d4->next)
			a->d4 = a->d4->next;
		a->d4->next = a->d2;
		a->d1 = a->d1->next;
	}
}

int			add_elements_first(t_rel *a, t_all *all, int i, t_relations **s)
{
	int		z;

	z = 0;
	while (a->d4)
	{
		a->d1 = s[i];
		while (a->d1)
		{
			if (ft_strcmp(a->d1->rel, all->en) == 0 ||
				ft_strcmp(a->d1->rel, all->st) == 0)
			{
				a->d1 = a->d1->next;
				continue;
			}
			if (ft_strcmp(a->d1->rel, a->d4->rel) == 0)
				z = -1;
			a->d1 = a->d1->next;
		}
		a->d4 = a->d4->next;
	}
	return (z);
}

void		next_iter_funct(t_all *all, t_rel *a, t_relations **s, int tumba)
{
	int		i;
	int		z;

	i = 0;
	while (i <= all->a)
	{
		if (i == tumba)
			i++;
		while (s[i] == NULL && i <= all->a)
			i++;
		if (i > all->a)
			break ;
		a->d4 = a->d3;
		a->d1 = s[i];
		z = add_elements_first(a, all, i, s);
		a->d4 = a->d3;
		a->d1 = s[i];
		if (z != -1)
		{
			all->t[all->m].i = i;
			all->m++;
		}
		add_elements(a, z, all);
		i++;
	}
}

void		inter(t_all *all, t_relations **s, int tumba)
{
	t_rel	a;
	t_tint	d[100];
	int		ddd;

	a.d1 = s[tumba];
	copy_ther_row(all, &a, tumba);
	next_iter_funct(all, &a, s, tumba);
	all->t[all->m].i = -1;
	ddd = 0;
	while (all->t[ddd].i > -1)
	{
		d[ddd].i = all->t[ddd].i;
		ddd++;
	}
	d[ddd].i = -1;
	a.d4 = a.d3;
	while (a.d4)
	{
		a.d2 = a.d4;
		a.d4 = a.d4->next;
		free(a.d2->rel);
		free(a.d2);
	}
}
