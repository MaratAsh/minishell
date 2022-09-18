//
// Created by Altagracia Cierra on 9/18/22.
//

#include "minishell.h"
#include "minishell_parser.h"

t_token *exec_tkn(void)
{
	t_tkn_exec	*cmd;

	cmd = malloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = TOKEN_EXEC;
	return (t_token*)cmd;
}

t_token	*redir_tkn(t_token *subtkn, char *file, char *efile, int mode, int fd)
{
	t_tkn_redir	*tkn;

	tkn = malloc(sizeof(*tkn));
	memset(tkn, 0, sizeof(*tkn));
	tkn->type = TOKEN_REDIR;
	tkn->token = subtkn;
	tkn->file = file;
	tkn->efile = efile;
	tkn->mode = mode;
	tkn->fd = fd;
	return ((t_token *) tkn);
}

t_token	*pipe_tkn(t_token *left, t_token *right)
{
	t_tkn_pipe	*cmd;

	cmd = malloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = TOKEN_PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_token *)cmd);
}

t_token	*list_tkn(t_token *left, t_token *right)
{
	t_tkn_list	*cmd;

	cmd = malloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = TOKEN_LIST;
	cmd->left = left;
	cmd->right = right;
	return ((t_token *)cmd);
}

t_token *back_tkn(t_token *subtkn)
{
	t_tkn_back	*cmd;

	cmd = malloc(sizeof(*cmd));
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = TOKEN_BACKGROUND;
	cmd->token = subtkn;
	return ((t_token *)cmd);
}

