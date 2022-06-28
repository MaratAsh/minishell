/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/14 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_shell
{
	char	*expression;
	int 	argc;
	char	**argv;
	char	**env;
	int 	process_count;
	pid_t	*processes_id;
}				t_shell;

int	minishell_prepare(t_shell *shell, int argc, char *argv[], char *env[]);
int	minishell_start(t_shell *shell);

#endif
