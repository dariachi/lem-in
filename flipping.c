#include "lemin.h"

t_relations	*ft_malloc(char *str)
{
	t_relations *s;

	s = malloc(sizeof(t_relations));
	s->next = NULL;
	s->rel = ft_strdup(str);
	s->r = 0;
	return s;
}

void	ft_free(t_relations *d)
{
	free(d->next->rel);
	free(d->next);
	d->next = NULL;
}

int	flipping(t_all *all, t_relations **s, int i)
{
	t_relations *d1, *d2, *d3, *d4;
	t_relations *c;

	d1 = s[i];
	while(d1 && d1->next && d1->next->next)
		d1 = d1->next;
	d2 = ft_malloc(d1->next->rel);
	ft_free(d1);

	d3 = d2;
	d1 = s[i];
	while(d1->next)
	{
		while(d1->next)
		{
			c = d1;
			d1 = d1->next;
		}
		d4 = ft_malloc(d1->rel);
		while(d3->next)
			d3 = d3->next;
		d3->next = d4;
		free(d1->rel);
		free(d1);
		c->next = NULL;
		d1 = NULL;
		d1 = s[i];
	}
	d4 = ft_malloc(d1->rel);
	while(d3->next)
		d3 = d3->next;
	d3->next = d4;
	free(c->rel);
	free(c);
	s[i] = NULL;
	s[i] = d2;
	return 1;
}