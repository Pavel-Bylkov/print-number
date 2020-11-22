/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:10:39 by whector           #+#    #+#             */
/*   Updated: 2020/09/06 20:15:10 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_head.h"

void	clean_spaces(char *str, int *i)
{
	while (str[*i] == ' ')
		*i = *i + 1;
}

int		str_clean(char *find_buf)
{
	int		i[2];
	char	tmp[500];

	i[0] = 0;
	i[1] = 0;
	clean_spaces(find_buf, &i[0]);
	if (find_buf[i[0]++] != ':')
		return (1);
	clean_spaces(find_buf, &i[0]);
	while (find_buf[i[0]])
	{
		if (find_buf[i[0]] < 32 || find_buf[i[0]] > 126)
			return (1);
		if (find_buf[i[0] - 1] == ' ')
			clean_spaces(find_buf, &i[0]);
		tmp[i[1]++] = find_buf[i[0]++];
	}
	while (tmp[i[1] - 1] == ' ')
		i[1]--;
	tmp[i[1]] = '\0';
	i[0] = -1;
	while (tmp[++i[0]])
		find_buf[i[0]] = tmp[i[0]];
	find_buf[i[0]] = '\0';
	return (0);
}

char	*create_str(char *buf, char *key)
{
	char	*str;
	int		i;
	char	find_buf[500];

	find_str_in_buf(buf, key, find_buf);
	if (str_clean(find_buf))
		return (NULL);
	str = (char *)malloc(sizeof(char) * len_str(find_buf) + 1);
	i = -1;
	while (find_buf[++i])
		str[i] = find_buf[i];
	str[i] = '\0';
	return (str);
}

int		ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = -1;
	while (str1[++i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (-str2[i]);
}
