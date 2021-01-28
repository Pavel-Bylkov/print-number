#ifndef RUSH_HEAD_H
# define RUSH_HEAD_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	char			*key;
	char			*str;
}					t_dict;

int					ft_atoi(char *arg);
int					check_nbr(int size, char *nbr);
int					check_source(int *fd, char *fname);
int					check_buf_key(char *key, char *buf, int flag);
int					check_buf_str(char *buf);
int					valid_str_dict(char *buf, int *i);
int					check_dubl(char *key, char *buf);
t_dict				*create_dict(int fd);
char				*create_key(int n);
char				*create_str(char *buf, char *key);
void				write_nbr(t_dict *dict, int size, char *nbr);
void				free_dict(t_dict *dict);
void				btree_insert_node(t_dict **dict, char *key, char *str);
int					ft_strcmp(char *str1, char *str2);
int					len_str(char *str);
void				find_str_in_buf(char *buf, char *key, char *find_buf);
void				clean_spaces(char *str, int *i);
int					str_clean(char *find_buf);
void				btree_insert_elem(t_dict *root, t_dict *new_node);
t_dict				*btree_create_node(char *key, char *str);
void				analis_nbr(int s, char *nbr, char **numbers);
void				analis_nbr2(int s, char *n, char **nbrs, int *i);
int					num_1(char nbr, char **str_out, int *i);
int					str_copy_numbr_1(char nbr, char **str_out, int *i);
int					str_copy_numbr_19(char *nbr, int *i, char **str_out);
int					str_copy_numbr_20(char nbr, char **str_out, int *i);
void				str_copy_numbr_0(int nul, char **str_out, int *j);
void				str_copy(char *src, char *out);
char				*find_str_in_dict(t_dict *root, char *number);

#endif
