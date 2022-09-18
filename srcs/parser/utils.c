//
// Created by Altagracia Cierra on 9/18/22.
//

#include "minishell.h"
#include "minishell_parser.h"

int	fork_alert(void)
{
	int pid;

	pid = fork();
	if(pid == -1)
		exit_alert("fork error", ERROR_FORK);
	return (pid);
}
