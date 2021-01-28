#include "rush_head.h"

void	btree_insert_node(t_dict **dict, char *key, char *str)
{
	t_dict	*new_node;
	t_dict	*tmp;

	new_node = btree_create_node(key, str);
	if (new_node == 0)
		return ;
	if (*dict == NULL)
		*dict = new_node;
	else
	{
		tmp = *dict;
		btree_insert_elem(tmp, new_node);
	}
}

void	btree_insert_elem(t_dict *root, t_dict *new_node)
{
	if (ft_strcmp(new_node->key, root->key) > 0)
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			btree_insert_elem(root->right, new_node);
	}
	else
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			btree_insert_elem(root->left, new_node);
	}
}

t_dict	*btree_create_node(char *key, char *str)
{
	t_dict		*elem;

	elem = malloc(sizeof(t_dict));
	if (elem == NULL)
		return (NULL);
	elem->left = NULL;
	elem->right = NULL;
	elem->key = key;
	elem->str = str;
	return (elem);
}

char	*find_str_in_dict(t_dict *root, char *number)
{
	char	*find_str;

	if (root == NULL)
		return (NULL);
	if (ft_strcmp(number, root->key) == 0)
		return (root->str);
	find_str = NULL;
	if (root->left != NULL)
		find_str = find_str_in_dict(root->left, number);
	if (root->right != NULL && find_str == NULL)
		find_str = find_str_in_dict(root->right, number);
	return (find_str);
}

void	free_dict(t_dict *dict)
{
	t_dict	*tmp;

	tmp = dict;
	if (tmp->left != NULL)
		free_dict(tmp->left);
	free(tmp->key);
	free(tmp->str);
	if (tmp->right != NULL)
		free_dict(tmp->right);
	tmp = NULL;
	free(dict);
}
