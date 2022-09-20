/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/20 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_edit(t_dlist *app, char *key, char *value)
{
	t_dlist				*curr;
	struct s_env_item	*env;
	int					keylen;

	curr = app;
	keylen = ft_strlen(key);
	while (curr)
	{
		env = (struct s_env_item *) curr->content;
		if (ft_strnstr(key, env->key, keylen))
		{
			free(env->value);
			env->value = value;
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}
