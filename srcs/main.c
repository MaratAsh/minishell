/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/06/28 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


t_list	*get_commands(char *user_input, t_dlist	*env)
{
	t_dlist	*lexer_tokens;
	t_list *command_list;

	validation_input(user_input, env);

	lexer_tokens = lexer(user_input, env);

	command_list = parser(lexer_tokens, env);


	return (command_list);
}

int	main(int argc, char *argv[], char *env[])
{
	t_shell	*shell_data;
	char	*user_input;
	t_list	*command_list;

	shell_data = shell_data_init(argc, argv, env);
	if (!shell_data)
		return (0);


	while (1)
	{
		ft_putendl_fd("mini-shell $ ", 1);
		user_input = readline(NULL);
		command_list = get_commands(user_input, shell_data->env);
		if (!command_list)
			return (0);
		executor(command_list);
	}


	return (0);
}
