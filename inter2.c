#include "lemin.h"

void	inter(t_all *all, t_relations **s, int tumba)
{
	int numb = 0;
	int z = 0;
	t_relations *d1, *d2, *d3, *d4;
	d3 = malloc(sizeof(t_relations));
	d4 = d3;

	d1 = s[tumba];
									//копируем текущий рядок

	all->m = 0;
	all->t[all->m].i = tumba;
	all->m++;
	d4->rel = ft_strdup(d1->rel);
	d4->next = NULL;
	d1 = d1->next;
	while(d1)
	{
		d2 = malloc(sizeof(t_relations));
		d2->next = NULL;
		d2->rel = ft_strdup(d1->rel);
		while(d4->next)
			d4 = d4->next;
		d4->next = d2;
		d1 = d1->next;
	}

	int i = 0;
	int f = 1;
	while(i <= all->a)						//смотрит есть ли повторения
	{
		if(i == tumba)
			i++;

		while(s[i] == NULL && i <= all->a)
			i++;
		if(i > all->a)
			break ;
		d4 = d3;
		d1 = s[i];
		z = 0;
		while(d4)
		{
			d1 = s[i];
			while(d1)
			{
				if(ft_strcmp(d1->rel, all->en) == 0 || ft_strcmp(d1->rel, all->st) == 0)
				{

					d1 = d1->next;
					continue;
				}
				if(ft_strcmp(d1->rel, d4->rel) ==0)
					z = -1;
				d1 = d1->next;
			}
			d4 = d4->next;
		}

		d4 = d3;
		d1 = s[i];

		if(z != -1)
		{
			all->t[all->m].i = i;
			all->m++;
			f++;
		}
		while(d1 && z != -1)
		{
			if(ft_strcmp(d1->rel, all->en) == 0 || ft_strcmp(d1->rel, all->st) == 0) 		//дописует эллементы в структуру
			{
				d1 = d1->next;
				continue;
			}
			d2 = malloc(sizeof(t_relations));
			d2->next = NULL;
			d2->rel = ft_strdup(d1->rel);
			while(d4->next)
				d4 = d4->next;
			d4->next = d2;
			d1 = d1->next;
		}
		i++;
	}
	all->t[all->m].i = -1;
	t_tint d[100];
	int ddd = 0;
	while(all->t[ddd].i > -1)
	{
		d[ddd].i = all->t[ddd].i;
		ddd++;
	} 
	d[ddd].i = -1;



	d4 = d3;
	while(d4)
	{
		d2 = d4;
		d4 = d4->next;
		free(d2->rel);
		free(d2);
	}
}