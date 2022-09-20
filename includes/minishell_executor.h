/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/20 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_EXECUTOR_H
#define MINISHELL_EXECUTOR_H

# include "minishell.h"

# define BUILTINS_COUNT 3
# define BUILTINS_NAMES "env", "exit"
# define BUILTINS_FUNCTIONS built_in_env, built_in_exit

int	built_in_env(t_tkn_exec *token, t_app *app);
int	built_in_exit(t_tkn_exec *token, t_app *app);

typedef int	(*t_exec_function)(t_tkn_exec *token, t_app *app);

#endif
