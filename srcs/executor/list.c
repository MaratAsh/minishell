/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/25 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_executor.h"
#include "minishell.h"


int	execute_list_(t_token *token, t_app *app)
{
	pid_t	pid;
	int 	ret;

	pid = fork();
	if (pid)
	{
		waitpid(pid, &ret, 0);
	}
	else
	{
		exit(executor(token, app));
	}
	return (ret);
}

int	execute_list(t_tkn_list *token, t_app *app)
{
	int ret;

	ret = execute_list_(token->right, app);
	ret = execute_list_(token->left, app);
	return (ret);
}
