/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/20 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	env_insert(t_dlist **envpp, char *key, char *value)
{
	t_dlist				*curr;
	t_dlist				*end;
	struct s_env_item	*env;
	int					keylen;

	curr = *envpp;
	keylen = ft_strlen(key);
	if (!curr)
	{
		env = malloc(sizeof(struct s_env_item));
		env->key = key;
		env->value = value;
		curr = ft_dlstnew(env);
		*envpp = curr;
		return (0);
	}
	while (curr)
	{
		env = (struct s_env_item *) curr->content;
		if (ft_strnstr(key, env->key, keylen))
			return (1);
		if (curr->next == NULL)
			end = curr;
		curr = curr->next;
	}
	env = malloc(sizeof(struct s_env_item));
	env->key = key;
	env->value = value;
	curr = ft_dlstnew(env);
	ft_dlstadd_after(end, curr);
	return (0);
}
