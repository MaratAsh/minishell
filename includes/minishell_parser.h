/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 1970/01/11 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_PARSER_H
#define MINISHELL_PARSER_H

# include <stdlib.h>
# include "minishell.h"

int		fork_alert(void);

t_token	*parseline(char**, char*);
t_token	*parsepipe(char**, char*);
t_token	*parseexec(char**, char*);
t_token	*nulterminate(t_token *);

// constructors
t_token *exec_tkn(void);
t_token	*redir_tkn(t_token *subtkn, char *file, char *efile, int mode, int fd);
t_token	*pipe_tkn(t_token *left, t_token *right);
t_token	*list_tkn(t_token *left, t_token *right);
t_token *back_tkn(t_token *subtkn);

#endif
