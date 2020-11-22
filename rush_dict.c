/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:03:07 by whector           #+#    #+#             */
/*   Updated: 2020/09/06 22:20:12 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_head.h"

t_dict	*create_dict(int fd)
{
	char	buf[4096];
	t_dict	*dict;
	int		i;
	char	*key;
	int		rb;

	rb = read(fd, buf, 4096);
	close(fd);
	dict = NULL;
	i = -1;
	while (++i < 41 && rb > 0)
	{
		buf[rb] = '\0';
		key = create_key(i);
		if (create_str(buf, key) == NULL)
			rb = -1;
		btree_insert_node(&dict, key, create_str(buf, key));
	}
	if (rb <= 0)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	return (dict);
}

char	*create_key(int n)
{
	char	*key;
	int		i[3];
	char	*a_key;

	a_key = "20-10-1000000-5-15-70-1000000000000000000000000-2-8-13-18-50-100-"
		"1000000000000000-1000000000000000000000000000000000-0-3-7-12-17-40-90-"
		"1000000000000-1000000000000000000000-1000000000000000000000000000000-"
		"1-4-6-9-11-14-16-19-30-60-80-1000-1000000000-1000000000000000000-"
		"1000000000000000000000000000-1000000000000000000000000000000000000-";
	key = (char *)malloc(sizeof(char) * 40);
	i[0] = -1;
	i[2] = -1;
	while (a_key[++i[0]] && (++i[2] + 1 > 0))
	{
		i[1] = 0;
		while (a_key[i[0]] != '-')
		{
			if (i[2] == n)
				key[i[1]++] = a_key[i[0]];
			i[0]++;
		}
		if (i[2] == n)
			key[i[1]] = '\0';
	}
	return (key);
}

int		len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	find_str_in_buf(char *buf, char *key, char *find_buf)
{
	int		i[3];
	int		flag;

	i[0] = -1;
	while (buf[++i[0]])
	{
		if (buf[i[0]] == key[0])
		{
			if (i[0] == 0 || buf[i[0] - 1] == '\n')
			{
				flag = 1;
				i[1] = 1;
				i[2] = i[0] + 1;
				while (key[i[1]] && flag)
					flag = (buf[i[2]++] != key[i[1]++]) ? 0 : 1;
				if (flag && (buf[i[2]] == ' ' || buf[i[2]] == ':'))
					break ;
			}
		}
	}
	i[0] = 0;
	while (buf[i[2]] != '\n')
		find_buf[i[0]++] = buf[i[2]++];
	find_buf[i[0]] = '\0';
}
