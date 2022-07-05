/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:29:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:50 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_dlstsize(t_dlist *dlst)
{
	size_t	i;

	i = 1;
	if (!dlst)
		return (0);
	while (dlst && dlst->next)
	{
		dlst = dlst->next;
		++i;
	}
	return (i);
}
