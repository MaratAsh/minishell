/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_alert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/09/18 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_alert(char *message, int code)
{
	int		len;
	char	*str;

	len = ft_strlen(message);
	str = malloc(len + 2);
	if (!str)
	{
		write(2, message, len);
		write(2, "\n", 1);
		exit(code);
	}
	ft_strlcpy(str, message, len);
	ft_strlcpy(str + len, "\n", 2);
	write(2, str, len + 1);
	free(str);
	exit(code);
}
