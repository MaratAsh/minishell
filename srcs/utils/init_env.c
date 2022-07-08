#include "../../includes/libft.h"

t_dlist *init_env(char **old_env)
{
	t_dlist	*new_env;
	t_dlist *tmp_dlist;
	char *tmp_str;
	int i;

	tmp_str = ft_strdup(old_env[0]);
	if (!tmp_str)
		return (NULL);
	new_env = ft_dlstnew(tmp_str);
	if (!new_env)
		return (NULL);

	i = 1;
	while (old_env[i])
	{
		tmp_str = ft_strdup(old_env[i]);
		if (!tmp_str)
			return (NULL);
		tmp_dlist = ft_dlstnew(tmp_str);
		if (!tmp_dlist)
			return (NULL);
		ft_dlstadd_after(new_env, tmp_dlist);
		new_env = new_env->next;
		i++;
	}
	new_env = ft_dlstfirst(new_env);
	return (new_env);
}
