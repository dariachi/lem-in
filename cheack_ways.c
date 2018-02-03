#include "lemin.h"

int 	flip_and_len_ways(t_all *all, t_tint *d, t_relations **z)
{
	t_relations *d1;
	int t = 0;
	int j = 0; 
	int len = 0;

	while(d[t].i != -1)
	{
		if(flipping(all, z, d[t].i) == 0)
			return 0;
		t++;
	}
	while(d[j].i != -1)
	{
		d1 = z[d[j].i];
		len = 0;
		while(d1)
		{
			len++;
			d1 = d1->next;
		}
		d[j].len = len - 1;
		j++;
	}
	d[j].len = 1000;
	return 1;
}

void	write_str(char **s)
{
	int c = 0;
	while(s[c] != NULL)
	{
		ft_putstr(s[c]);
		ft_putchar('\n');
		c++;
	}
	ft_putchar('\n');
}

void	last_way(t_all *all, t_relations **z)
{
	t_relations *k1;

	for (int a = 0; a <= all->a; a++)
	{
		k1 = z[a];
		while(k1->next)
			k1 = k1->next;
		if(ft_strcmp(all->st, k1->rel) != 0)
			z[a] = NULL;
	}
}