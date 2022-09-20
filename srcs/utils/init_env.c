#include "minishell.h"

static t_dlist	*convert_env(char *old_env)
{
	char				*tmp;
	struct s_env_item	*item;
	t_dlist				*dlist;

	tmp = ft_strchr((const char *) old_env, (int) '=');
	if (!tmp)
		return (NULL);
	*tmp = 0;
	tmp++;
	tmp = ft_strdup((const char *) tmp);
	if (!tmp)
		return (NULL);
	item = malloc(sizeof(struct s_env_item));
	if (!item)
	{
		free(tmp);
		return (NULL);
	}
	item->value = tmp;
	item->key = ft_strdup((const char *) old_env);
	if (!item->key)
	{
		free(tmp);
		free(item);
		return (NULL);
	}
	dlist = ft_dlstnew(item);
	if (!dlist)
	{
		free(item->key);
		free(item->value);
		free(item);
		return (NULL);
	}
	return (dlist);
}

t_dlist	*init_env(char **old_env)
{
	t_dlist	*head;
	t_dlist	*prev_env;
	t_dlist	*tmp_dlist;
	int		i;

	i = 1;
	head = NULL;
	while (old_env[i])
	{
		tmp_dlist = convert_env(old_env[i]);
		if (!tmp_dlist)
			return (NULL);
		if (!head)
			head = tmp_dlist;
		else
			ft_dlstadd_after(prev_env, tmp_dlist);
		prev_env = tmp_dlist;
		i++;
	}
	return (head);
}
