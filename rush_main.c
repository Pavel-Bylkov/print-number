#include "rush_head.h"

int		main(int argc, char **argv)
{
	t_dict		*dict;
	int			fd;
	int			size;
	char		*nbr;
	char		*fname;

	if (argc < 2 || argc > 3)
		return (0);
	fname = (argc == 2) ? "numbers.dict" : argv[1];
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (2);
	size = (argc == 2) ? ft_atoi(argv[1]) : ft_atoi(argv[2]);
	nbr = (argc == 2) ? argv[1] : argv[2];
	if (check_nbr(size, nbr) || check_source(&fd, fname))
		return (1);
	dict = create_dict(fd);
	if (dict == NULL)
		return (1);
	write_nbr(dict, size, nbr);
	free_dict(dict);
	return (0);
}

int		ft_atoi(char *arg)
{
	int i[2];
	int k;

	i[0] = 0;
	i[1] = 0;
	while (arg[i[0]] == ' ')
		i[0]++;
	k = 1;
	while (arg[i[0]] == '-' || arg[i[0]] == '+')
	{
		if (arg[i[0]++] == '-')
			k = -k;
	}
	while (arg[i[0]] == '0' && arg[i[0] + 1] != '\0')
		i[0]++;
	while (arg[i[0]] != '\0')
	{
		if (arg[i[0]] < '0' || arg[i[0]] > '9')
			return (-1);
		i[0]++;
		i[1]++;
	}
	return (i[1] * k);
}

int		check_nbr(int size, char *nbr)
{
	char	buf[40];
	int		i;
	int		j;

	if (size > 0 && size < 40)
	{
		i = len_str(nbr) - size;
		j = 0;
		while (nbr[i])
			buf[j++] = nbr[i++];
		buf[j] = '\0';
		i = -1;
		while (buf[++i])
			nbr[i] = buf[i];
		nbr[i] = '\0';
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int		check_source(int *fd, char *fname)
{
	char	buf[4096];
	int		rb;
	int		i;
	char	*key;

	rb = read(*fd, buf, 4096);
	i = -1;
	while (++i < 41 && rb > 0)
	{
		buf[rb] = '\0';
		key = create_key(i);
		if (check_buf_key(key, buf, 0))
			rb = -1;
	}
	if (check_buf_str(buf))
		rb = -1;
	close(*fd);
	if (rb <= 0)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	*fd = open(fname, O_RDONLY);
	return (0);
}
