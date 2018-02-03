/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:43:05 by dchirkin          #+#    #+#             */
/*   Updated: 2017/02/24 11:57:51 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>

# define BUFF_SIZE 4

int		get_next_line(const int fd, char **line);
int		poss(char *str, char c, int g);
int		sear(char *rob, int fd, char **line);
int		w(int ret, char **line, int fd, char *rob);
int		kkk(char *rob, char *n, char **line);

#endif
