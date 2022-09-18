/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/28 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_parser.h"
#include <fcntl.h>


char whitespace[] = " \t\r\n\v";
char symbols[] = "<|>&;()";

int	gettoken(char **ps, char *es, char **q, char **eq)
{
	char *s;
	int ret;

	s = *ps;
	while(s < es && strchr(whitespace, *s))
		s++;
	if(q)
		*q = s;
	ret = *s;
	switch(*s){
		case 0:
			break;
		case '|':
		case '(':
		case ')':
		case ';':
		case '&':
		case '<':
			s++;
			break;
		case '>':
			s++;
			if(*s == '>'){
				ret = '+';
				s++;
			}
			break;
		default:
			ret = 'a';
			while(s < es && !strchr(whitespace, *s) && !strchr(symbols, *s))
				s++;
			break;
	}
	if(eq)
		*eq = s;

	while(s < es && strchr(whitespace, *s))
		s++;
	*ps = s;
	return ret;
}

int	peek(char **ps, char *es, char *toks)
{
	char *s;

	s = *ps;
	while(s < es && strchr(whitespace, *s))
		s++;
	*ps = s;
	return *s && strchr(toks, *s);
}

t_token *parsecmd(char *s)
{
	char *es;
	t_token	*token;

	es = s + strlen(s);
	token = parseline(&s, es);
	peek(&s, es, "");
	if(s != es)
	{
		exit_alert("syntax", ERROR_SYNTAX);
	}
	nulterminate(token);
	return (token);
}

t_token *parseline(char **ps, char *es)
{
	t_token *tkn;

	tkn = parsepipe(ps, es);
	while(peek(ps, es, "&")){
		gettoken(ps, es, 0, 0);
		tkn = back_tkn(tkn);
	}
	if(peek(ps, es, ";")){
		gettoken(ps, es, 0, 0);
		tkn = list_tkn(tkn, parseline(ps, es));
	}
	return tkn;
}

t_token	*parsepipe(char **ps, char *es)
{
	t_token *tkn;

	tkn = parseexec(ps, es);
	if(peek(ps, es, "|")){
		gettoken(ps, es, 0, 0);
		tkn = pipe_tkn(tkn, parsepipe(ps, es));
	}
	return tkn;
}

t_token	*parseredirs(t_token *tkn, char **ps, char *es)
{
	int		tok;
	char	*q;
	char	*eq;

	while(peek(ps, es, "<>")){
		tok = gettoken(ps, es, 0, 0);
		if(gettoken(ps, es, &q, &eq) != 'a')
			exit_alert("missing file for redirection", ERROR_REDIR_FILE_MISSING);
		switch(tok){
			case '<':
				tkn = redir_tkn(tkn, q, eq, O_RDONLY, 0);
				break;
			case '>':
				tkn = redir_tkn(tkn, q, eq, O_WRONLY | O_CREAT, 1);
				break;
			case '+':  // >>
				tkn = redir_tkn(tkn, q, eq, O_WRONLY | O_CREAT, 1);
				break;
		}
	}
	return tkn;
}

t_token *parseblock(char **ps, char *es)
{
	t_token *tkn;

	if(!peek(ps, es, "("))
		exit_alert("parseblock", ERROR_PARSE_BLOCK);
	gettoken(ps, es, 0, 0);
	tkn = parseline(ps, es);
	if(!peek(ps, es, ")"))
		exit_alert("syntax - missing )", ERROR_SYNTAX_MISSING_RPAR);
	gettoken(ps, es, 0, 0);
	tkn = parseredirs(tkn, ps, es);
	return tkn;
}

t_token *parseexec(char **ps, char *es)
{
	char *q, *eq;
	int tok, argc;
	t_tkn_exec *tknexec;
	t_token	*ret;

	if(peek(ps, es, "("))
		return parseblock(ps, es);

	ret = exec_tkn();
	tknexec = (t_tkn_exec *)ret;

	argc = 0;
	ret = parseredirs(ret, ps, es);
	while(!peek(ps, es, "|)&;")){
		if((tok=gettoken(ps, es, &q, &eq)) == 0)
			break;
		if(tok != 'a')
			exit_alert("syntax", ERROR_SYNTAX);
		tknexec->argv[argc] = q;
		tknexec->eargv[argc] = eq;
		argc++;
		if(argc >= MAXARGS)
			exit_alert("too many args", ERROR_TOO_MANY_ARGS);
		ret = parseredirs(ret, ps, es);
	}
	tknexec->argv[argc] = 0;
	tknexec->eargv[argc] = 0;
	return ret;
}

// NUL-terminate all the counted strings.
t_token *nulterminate(t_token *cmd)
{
	int			i;
	t_tkn_back	*bcmd;
	t_tkn_exec	*ecmd;
	t_tkn_list	*lcmd;
	t_tkn_pipe	*pcmd;
	t_tkn_redir	*rcmd;

	if(cmd == 0)
		return 0;
	switch(cmd->type){
		case TOKEN_EXEC:
			ecmd = (t_tkn_exec *)cmd;
			for(i=0; ecmd->argv[i]; i++)
				*ecmd->eargv[i] = 0;
			break;

		case TOKEN_REDIR:
			rcmd = (t_tkn_redir *)cmd;
			nulterminate(rcmd->token);
			*rcmd->efile = 0;
			break;

		case TOKEN_PIPE:
			pcmd = (t_tkn_pipe *)cmd;
			nulterminate(pcmd->left);
			nulterminate(pcmd->right);
			break;

		case TOKEN_LIST:
			lcmd = (t_tkn_list *)cmd;
			nulterminate(lcmd->left);
			nulterminate(lcmd->right);
			break;

		case TOKEN_BACKGROUND:
			bcmd = (t_tkn_back *)cmd;
			nulterminate(bcmd->token);
			break;
	}
	return cmd;
}



t_token 	*parser(char *input, t_app *app)
{
	t_token	*tokens;

	(void) input; (void) app;
	tokens = parsecmd(input);
	return (tokens);
}
