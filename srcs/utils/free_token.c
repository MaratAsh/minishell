/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/18 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_token(t_token *tkn)
{
	if (tkn->type == TOKEN_REDIR)
	{
		free_token(((t_tkn_redir *) tkn)->token);
	}
	else if (tkn->type == TOKEN_PIPE)
	{
		free_token(((t_tkn_pipe *) tkn)->right);
		free_token(((t_tkn_pipe *) tkn)->left);
	}
	else if (tkn->type == TOKEN_LIST)
	{
		free_token(((t_tkn_list *) tkn)->right);
		free_token(((t_tkn_list *) tkn)->left);
	}
	else if (tkn->type == TOKEN_BACKGROUND)
	{
		free_token(((t_tkn_back *) tkn)->token);
	}
	free(tkn);
	return (0);
}
