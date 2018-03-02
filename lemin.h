/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:30:57 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/30 14:31:00 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define INT 2147483647
# include <stdlib.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct			s_node
{
	int					x;
	int					y;
	char				*name;
	int					count;
	char				k;
	struct s_node		*next;
}						t_node;

typedef struct			s_truck
{
	char				*f;
	char				*s;
	int					c_f;
	int					c_s;
	struct s_truck		*next;
}						t_truck;

typedef struct			s_relations
{
	char				*rel;
	int					r;
	int					len;
	struct s_relations	*next;
}						t_relations;

typedef	struct			s_tint
{
	int					i;
	int					len;
}						t_tint;

typedef struct			s_num
{
	int					u;
	int					x;
	int					len;
	int					y;
	int					c;
	int					k;
}						t_num;

typedef struct			s_rel
{
	t_relations			*d1;
	t_relations			*d2;
	t_relations			*d3;
	t_relations			*d4;
	t_relations			*c;
}						t_rel;

typedef struct			s_all
{
	t_node				*room1;
	t_node				*room2;
	t_node				*room3;
	t_node				*room4;
	t_truck				*truck1;
	t_truck				*truck2;
	t_truck				*truck3;
	t_relations			*r;
	t_relations			*rcop;
	int					ants;
	int					index;
	char				*ants_str;
	int					start;
	int					end;
	int					current_name;
	int					o;
	int					found;
	int					aant;
	int					tt;
	int					i;
	int					j;
	int					jj;
	int					a;
	int					q;
	int					d;
	int					m;
	t_tint				t[100];
	char				*st;
	char				*en;
	t_relations			*d1;
	int					max_lines;
	int					f_s;
	t_num				cof;
}						t_all;

int						flipping(t_relations **s, int i);
void					inter(t_all *all, t_relations **s, int tumba);
void					ft_copy(t_all *all, t_relations **s, int i);
int						ft_number(int num);
int						number_ants(t_all *all, char *str);
int						start(t_all *all, char *str, char **s);
int						check_rooms(char *str, t_all *all);
int						valid_num(char *str);
int						end(t_all *all, char *str, char **s);
int						ft_serch_ants(t_all *all, char *str, char **s);
int						ft_position_def(t_all *all);
char					*truck_end(t_all *all, char *end);
void					serch_ways(t_all *all, char *way, t_relations **s);
int						are_there_any_ants(int *m, int ant);
void					move_ants(t_all *all, t_relations **z,
							t_tint *d, int *mas);
int						check_links(char *str, t_all *all, char **s);
int						cheak_all_rooms(t_all *all, char *str, char **s);
int						ft_cycle(t_all *all, char *str, char **s);
int						next_next_main(t_all *all, char **s, char *str);
void					serch_ways2(t_all *all, char *way, t_relations **s);
int						optimal_ways(t_all *all, t_tint *d, t_relations **z);
int						start_end_way(t_all *all, char **s);
int						building_the_way(t_all *all, t_relations **z, char **s);
int						flip_and_len_ways(t_all *all, t_tint *d,
							t_relations **z, int len);
void					write_str(char **s);
void					last_way(t_all *all, t_relations **z);
t_relations				**ft_creat_relations(t_all *all);
void					value_in_one(int *mas, t_all *all);
void					end_free(t_all *all, char **s);
void					malloc_room3(t_all *all);
int						embedded_loop(t_all *all, int *mas);
void					ft_write_ants(t_all *all);
int						cheak_repeats(t_all *all, int x, int y);
void					ft_malloc_truck(t_all *all, char *fir, char *sec);
void					ft_malloc_truck_2(t_all *all, char *ff, char *ss);
int						ft_build(t_all *all, char *truck,
								t_relations **z, char **s);
int						ft_write_an(int zz, char *en);
int						search_first_truck(t_all *all, char *sr);
void					truck_end2(t_all *all);
int						ft_fre_str(t_relations **z);
int						cheak(char *str, int x, int y, int i);
int						more_than_need_star_end(char *str);

#endif
