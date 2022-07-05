/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:00:00 by alcierra          #+#    #+#             */
/*   Updated: 2022/07/05 00:00:00 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	string_put_fd(t_string *str, int fd)
{
	if (!str)
		return ;
	if (str->str == NULL)
	{
		write(fd, "(null)", 6);
		return ;
	}
	write(fd, str->str, str->length);
}
