/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/20 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"

static int	print_env(struct s_env_item *env)
{
	char *tmp;
	size_t	sz_key;
	size_t	sz_value;
	size_t	sz_tmp;

	sz_key = ft_strlen(env->key);
	sz_value = ft_strlen(env->value);
	tmp = malloc(sz_key + 2 + sz_value);
	if (!tmp)
	{
		write(1, env->key, sz_key);
		write(1, "=", 1);
		write(1, env->value, sz_value);
		write(1, "\n", 1);
		return (0);
	}
	sz_tmp = ft_strlcpy(tmp, env->key, sz_key + 1);
	tmp[sz_tmp] = '=';
	sz_tmp++;
	sz_tmp += ft_strlcpy(tmp + sz_tmp, env->value, sz_value + 1);
	sz_tmp += ft_strlcpy(tmp + sz_tmp, "\n", 2);
	write(1, tmp, sz_tmp);
	free(tmp);
	return (0);
}

int	built_in_env(t_tkn_exec *token, t_app *app)
{
	t_dlist	*curr;

	(void) token;
	curr = app->env;
	while (curr)
	{
		print_env((struct s_env_item *) curr->content);
		curr = curr->next;
	}
	return (0);
}
