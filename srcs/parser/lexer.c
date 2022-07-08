#include "../../includes/minishell.h"

t_dlist *lexer(char *user_input, t_dlist	*env)
{
	t_dlist	*lexer_tokens;
	int i;
	int type;

	lexer_tokens = NULL;
	i = 0;
	while (user_input[i])
	{
		if (user_input[i] == '\'')
//			type = SINGLE_Q;
			add_single_q_token(lexer_tokens, user_input, i);
		else if (user_input[i] == '\"')
			type = DOUBLE_Q;
		else if (user_input[i] == '\\')
			type = BACK_SLASH;
		else if (user_input[i] == '|')
			type = PIPE;
	}

	return (lexer_tokens);
}