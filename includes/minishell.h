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
# include "libft.h"

# include <readline/readline.h>

struct	s_env_raw
{
	char	*path;
	char	**main;
};

struct	s_env
{
	char	**path;
};

typedef struct s_shell
{
	t_string welcome_message;
	char	*destination;
	char	*expression;
	int 	argc;
	char	**argv;
	int 	process_count;
	pid_t	*processes_id;
	struct s_env_raw	env_raw;
	struct s_env		env;
}				t_shell;

int	minishell_prepare(t_shell *shell, int argc, char *argv[], char *env[]);
int	minishell_start(t_shell *shell);

#endif
