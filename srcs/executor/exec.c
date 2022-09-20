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

#include "minishell_parser.h"
#include "minishell.h"

int	execute_exec(t_tkn_exec *token, t_app *app)
{
	(void) app;
	if (ft_strncmp(token->argv[0], "exit", 4) == 0)
		exit(0);
	printf("exec token: first argument: %s\n", token->argv[0]);
	return (0);
}
