/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:29:48 by alcierra          #+#    #+#             */
/*   Updated: 2022/03/10 19:41:44 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_dlstsize_full(t_dlist *dlst)
{
	size_t	i;

	while (dlst && dlst->prev)
		dlst = dlst->prev;
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
