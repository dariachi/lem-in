/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:50:05 by dchirkin          #+#    #+#             */
/*   Updated: 2016/12/10 13:28:27 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *string)
{
	int i;
	int zap;
	int neg;

	i = 0;
	zap = 0;
	neg = 0;
	while (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' ||
		string[i] == '\v' || string[i] == '\r' || string[i] == '\f')
		i++;
	if (string[i] == 45)
		neg = 1;
	if (string[i] == 43 || string[i] == 45)
		i++;
	while (string[i] >= 48 && string[i] <= 57)
	{
		zap = zap * 10 + (string[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-zap);
	else
		return (zap);
}
