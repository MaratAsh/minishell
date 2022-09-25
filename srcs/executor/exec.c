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

int execute_custom_file(const char *path, t_tkn_exec *token)
{
	if (access((const char *) path, X_OK) == 0)
	{
		return (execve((const char *) path, token->argv, NULL));
	}
	else
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd((char *) path, 2);
	}
	return (-1);
}

char *execute_find_custom_path_loop(char *path, char *cmd)
{
	char	*abscmd;
	size_t	l;
	size_t	prefix_len;

	l = ft_strlen(path);
	abscmd = ft_calloc(l + 1 + ft_strlen(cmd) + 1, sizeof(char));
	if (!abscmd)
		exit_alert("malloc: cannot allocate memory", 0);
	prefix_len = ft_strlcpy(abscmd, path, l + 1);
	abscmd[prefix_len] = '/';
	prefix_len++;
	prefix_len += ft_strlcpy(abscmd + prefix_len, cmd, ft_strlen(cmd) + 1);
	abscmd[prefix_len + 1] = 0;
	return (abscmd);
}

int	execute_find_custom(t_tkn_exec *token, t_app *app)
{
	char	*cmd;
	char	*abscmd;
	char	**path;
	size_t	l;

	cmd = token->argv[0];
	path = app->path;
	abscmd = NULL;
	if (!path)
		return (-1);
	if (cmd[0] == '/' || ft_strnstr(cmd, "./", 2))
	{
		l = (size_t) execute_custom_file(abscmd, token);
		return ((int) l);
	}
	while (*path)
	{
		abscmd = execute_find_custom_path_loop(*path, cmd);
		if (!abscmd)
			return (-1);
		if (access((const char *) abscmd, F_OK) == 0)
		{
			break;
		}
		free(abscmd);
		path++;
	}
	l = (size_t) execute_custom_file(abscmd, token);
	//free(abscmd);
	return ((int) l);
}

int	execute_exec(t_tkn_exec *token, t_app *app)
{
	t_exec_function	func;

	(void) app;
	func = get_built_in_function(token->argv[0]);
	if (func)
		return (func(token, app));
	return (execute_find_custom(token, app));
}
