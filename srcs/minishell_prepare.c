/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/28 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	minishell_prepare(t_shell *shell, int argc, char *argv[], char *env[])
{
	shell->expression = NULL;
	shell->argc = argc;
	shell->argv = argv;
	shell->env_raw.main = env;
	shell->process_count = 0;
	shell->processes_id = NULL;
	string_init(&(shell->welcome_message), "mini-shell $ ");
	return (0);
}
