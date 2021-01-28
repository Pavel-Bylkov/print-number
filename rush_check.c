#include "rush_head.h"

int		check_buf_key(char *key, char *buf, int flag)
{
	int	i[4];

	i[0] = -1;
	i[3] = 0;
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
					i[3]++;
			}
		}
	}
	if (i[3] == 0)
		return (1);
	else if (i[3] == 1)
		return (0);
	return (check_dubl(key, buf));
}

int		check_buf_str(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		while (buf[i] != '\n' && buf[i])
		{
			if (buf[i] == ' ')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '\0' || buf[i] == '\n')
					continue ;
				else
					return (1);
			}
			if (valid_str_dict(buf, &i))
				return (1);
		}
		i++;
	}
	return (0);
}

int		valid_str_dict(char *buf, int *i)
{
	if (buf[*i] < '0' || buf[*i] > '9')
		return (1);
	*i += 1;
	while (buf[*i] >= '0' && buf[*i] <= '9')
		*i += 1;
	while (buf[*i] == ' ')
		*i += 1;
	if (buf[*i] != ':')
		return (1);
	*i += 1;
	while (buf[*i] == ' ')
		*i += 1;
	while (buf[*i] >= 32 && buf[*i] <= 126)
		*i += 1;
	if (buf[*i] != '\0' && buf[*i] != '\n')
		return (1);
	return (0);
}

int		check_dubl(char *key, char *buf)
{
	(void)key;
	(void)buf;
	return (1);
}
