/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:09:07 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 19:09:09 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_gnl(char **line, char *rob)
{
	char *temp;

	temp = *line;
	*line = ft_strjoin(*line, rob);
	free(temp);
	ft_memset(rob, '\0', BUFF_SIZE);
}
