#include "rush_head.h"

void	write_nbr(t_dict *dict, int size, char *nbr)
{
	char	**numbers;
	char	*find_str;
	int		i[3];
	char	result[1024];

	i[0] = -1;
	numbers = (char **)malloc(size * 5 * sizeof(char *));
	while (++i[0] < size * 5)
		numbers[i[0]] = (char *)malloc(size + 1);
	analis_nbr(size, nbr, numbers);
	i[0] = -1;
	i[1] = 0;
	while (numbers[++i[0]][0] != '\0')
	{
		i[2] = 0;
		find_str = find_str_in_dict(dict, numbers[i[0]]);
		while (find_str != NULL && find_str[i[2]])
			result[i[1]++] = find_str[i[2]++];
		result[i[1]++] = (numbers[i[0] + 1][0] != '\0') ? ' ' : '\n';
	}
	write(1, &result[0], i[1]);
	i[0] = 0;
	while (i[0] < size * 5)
		free(numbers[i[0]++]);
	free(numbers);
}

void	analis_nbr(int s, char *nbr, char **numbers)
{
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < s)
	{
		analis_nbr2(s, nbr, numbers, i);
	}
	str_copy("", numbers[i[1]]);
}

void	analis_nbr2(int s, char *n, char **nbrs, int *i)
{
	int		f;
	int		raz;
	int		nul;

	if ((s - i[0] == 1) && n[i[0]] == '0')
		str_copy("0", nbrs[i[1]++]);
	raz = ((s - i[0]) % 3 == 0) ? 3 : (s - i[0]) % 3;
	nul = (raz == 3) ? ((s - i[0]) / 3 - 1) * 3 : ((s - i[0]) / 3) * 3;
	f = (raz == 3 && n[i[0]] > '0' && i[0] < s) ? num_1(n[i[0]++], nbrs, i) : 0;
	i[0] = (f == 0 && raz == 3 && n[i[0]] == '0' && i[0] < s) ? i[0] + 1 : i[0];
	if (raz > 1 && i[0] < s && n[i[0]] == '1')
		f = str_copy_numbr_19(n, i, nbrs);
	else
	{
		if (raz > 1 && i[0] < s && n[i[0]] > '1')
			f = str_copy_numbr_20(n[i[0]++], nbrs, i);
		else if (raz > 1 && n[i[0]] == '0' && i[0] < s)
			i[0]++;
		if (i[0] < s && n[i[0]] > '0')
			f = str_copy_numbr_1(n[i[0]++], nbrs, i);
		else if (i[0] < s && n[i[0]] == '0')
			i[0]++;
	}
	if (nul > 0 && f == 1)
		str_copy_numbr_0(nul, nbrs, i);
}

int		num_1(char nbr, char **str_out, int *i)
{
	char	str[2];

	str[0] = nbr;
	str[1] = '\0';
	str_copy(str, str_out[i[1]]);
	i[1] += 1;
	str_copy("100", str_out[i[1]]);
	i[1] += 1;
	return (1);
}

int		str_copy_numbr_1(char nbr, char **str_out, int *i)
{
	char	str[2];

	str[0] = nbr;
	str[1] = '\0';
	str_copy(str, str_out[i[1]]);
	i[1] += 1;
	return (1);
}
