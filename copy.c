#include "lemin.h"

void	ft_copy(t_all *all, t_relations **s, int i)
{
	t_relations *p;
	t_relations *p2 = s[all->a];
	t_relations *u;

	all->a++;
	s[all->a] = malloc(sizeof(t_relations));
	s[all->a]->next = NULL;
	p = s[all->a];

	p->rel = ft_strdup(p2->rel);
	i--;
	p2 = p2->next;
	while(p2 && i > 0)
	{
		u = malloc(sizeof(t_relations));
		u->next = NULL;
		u->rel = ft_strdup(p2->rel);
		while(p->next)
			p = p->next;
		p->next = u;
		p2 = p2->next;
		i--;
	}
	// p = s[all->a];
	// while(p)
	// {
	// 	printf("%s %d\n", p->rel, all->a);
	// 	p = p->next;
	// }
}