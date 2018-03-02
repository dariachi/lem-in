/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:08:52 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 15:08:54 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_write_ants(t_all *all)
{
	write(1, "L", 1);
	ft_putnbr(all->aant);
	write(1, "-", 1);
	ft_putstr(all->d1->rel);
	write(1, " ", 1);
}

int		embedded_loop(t_all *all, int *mas)
{
	int	found;

	found = 0;
	while (all->d1)
	{
		if (all->d1->r == all->aant)
		{
			all->d1->r = 0;
			all->d1 = all->d1->next;
			all->d1->r = all->aant;
			ft_write_ants(all);
			if (!ft_strcmp(all->d1->rel, all->en))
			{
				mas[all->aant - 1] = 0;
				all->d1->r = 0;
			}
			found = 1;
		}
		if (found)
			break ;
		all->d1 = all->d1->next;
	}
	return (found);
}
