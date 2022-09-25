/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/18 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_executor.h"

/*
 * Executor returns 0 when commands execute with success
 * */
int	executor(t_token *token, t_app *app)
{
	int		ret;
	pid_t	pid;

	ret = -1;
	if (token->type == TOKEN_EXEC)
	{
		pid = fork();
		if (pid)
			waitpid(pid, &ret, 0);
		else
		{
			ret = execute_exec((t_tkn_exec *) token, app);
			if (ret)
			{
				printf("smth happen!\n");
			}
			return (ret);
		}
	}
	else if (token->type == TOKEN_LIST)
		ret = execute_list((t_tkn_list *) token, app);
	app->exit_status = ret;
	return (0);
}
