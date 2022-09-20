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
#include "minishell_parser.h"

/*
 * Executor returns 0 when commands execute with success
 * */
int	executor(t_token *token, t_app *app)
{
	int	ret;

	if (token->type == TOKEN_EXEC)
	{
		ret = execute_exec((t_tkn_exec *) token, app);
		if (ret)
		{
			printf("smth happen!\n");
		}
	}
	(void) token; (void) app;
	return (0);
}
