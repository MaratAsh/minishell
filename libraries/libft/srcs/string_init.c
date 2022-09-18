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

void	string_init(t_string *str, char *ptr)
{
	if (str == NULL)
		return ;
	str->str = ptr;
	if (ptr)
		str->length = ft_strlen(ptr);
	else
		str->length = 0;
}
