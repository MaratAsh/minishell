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

#include "../minishell.h"

int	minishell_prepare(t_shell *shell, int argc, char *argv[], char *env[])
{
	shell->expression = NULL;
	shell->argc = argc;
	shell->argv = argv;
	shell->env = env;
	shell->process_count = 0;
	shell->processes_id = NULL;
	return (0);
}
