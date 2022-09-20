/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/18 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"
#include "minishell.h"


static t_exec_function	get_built_in_function(char *str)
{
	static char *builtins_name[BUILTINS_COUNT + 1] = {
			BUILTINS_NAMES,
			NULL
	};
	static int (*builtins_functs[BUILTINS_COUNT + 1])(t_tkn_exec *, t_app *) = {
			BUILTINS_FUNCTIONS,
			NULL
	};
	int 		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	while (builtins_name[i])
	{
		if (ft_strncmp(str, builtins_name[i], len) == 0)
			return (builtins_functs[i]);
		i++;
	}
	return (NULL);
}

int	execute_exec(t_tkn_exec *token, t_app *app)
{
	t_exec_function	func;

	(void) app;
	func = get_built_in_function(token->argv[0]);
	if (func)
		return (func(token, app));
	printf("exec token: first argument: %s\n", token->argv[0]);
	return (0);
}
