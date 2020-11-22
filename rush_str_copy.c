/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_str_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:25:41 by whector           #+#    #+#             */
/*   Updated: 2020/09/06 20:40:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_head.h"

int		str_copy_numbr_19(char *nbr, int *i, char **str_out)
{
	char	str[3];

	str[0] = nbr[i[0]];
	str[1] = nbr[i[0] + 1];
	str[2] = '\0';
	str_copy(str, str_out[i[1]]);
	i[0] += 2;
	i[1] += 1;
	return (1);
}

int		str_copy_numbr_20(char nbr, char **str_out, int *i)
{
	char	str[3];

	str[0] = nbr;
	str[1] = '0';
	str[2] = '\0';
	str_copy(str, str_out[i[1]]);
	i[1] += 1;
	return (1);
}

void	str_copy_numbr_0(int nul, char **str_out, int *j)
{
	char	*str;
	int		i;

	str = (char *)malloc(nul + 2);
	str[0] = '1';
	i = 1;
	while (i < nul + 1)
		str[i++] = '0';
	str[i] = '\0';
	str_copy(str, str_out[j[1]]);
	j[1] += 1;
	free(str);
}

void	str_copy(char *src, char *out)
{
	int i;

	i = -1;
	while (src[++i])
		out[i] = src[i];
	out[i] = '\0';
}
